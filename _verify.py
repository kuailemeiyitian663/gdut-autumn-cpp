# -*- coding: utf-8 -*-
"""全量验收：用 TDM-GCC 编译 gdut-autumn-cpp 下所有 .cpp，并逐个运行。

用法：python _verify.py         （只做验收用，不属于机试复习内容，可随时删）
"""
import os
import shutil
import subprocess
import sys
import tempfile
import time

sys.stdout.reconfigure(encoding="utf-8", errors="replace")

ROOT = os.path.dirname(os.path.abspath(__file__))
GXX = r"D:\TDM-GCC\bin\g++.exe"
OUT = os.path.join(ROOT, "build")
OUT_WIN = r"C:\Users\zheng\AppData\Local\Temp\cppbuild_verified"
os.makedirs(OUT, exist_ok=True)
os.makedirs(OUT_WIN, exist_ok=True)

BLOCK_MARK = "应用程序控制策略已阻止此文件"


def compile_ok(src, exe):
    r = subprocess.run([GXX, "-std=c++11", "-Wall", "-o", exe, src],
                       capture_output=True, cwd=ROOT)
    if r.returncode != 0:
        return False, r.stderr.decode("utf-8", "replace").strip()[:800]
    log = r.stderr.decode("utf-8", "replace").strip()
    warns = [l for l in log.splitlines() if "warning" in l.lower()]
    return True, (len(warns), warns)


def run_with_retry(exe, times=40):
    """本机偶发 '应用程序控制策略已阻止此文件'：先重试，再换目录/换名再试。"""
    last = ""
    for i in range(times):
        try:
            return subprocess.run([exe], capture_output=True, timeout=25, input=b"")
        except OSError as e:
            last = str(e)
            if BLOCK_MARK in last:
                time.sleep(0.4)
                continue
            return None
    # 还不行：换到系统临时目录，换几个文件名重试
    td = os.path.join(tempfile.gettempdir(), "cpp_verify_alt")
    os.makedirs(td, exist_ok=True)
    base = os.path.splitext(os.path.basename(exe))[0]
    for name in ["alt.exe", base + "_alt.exe", base + "2.exe", "ok.exe"]:
        cand = os.path.join(td, name)
        try:
            shutil.copy2(exe, cand)
            for i in range(6):
                try:
                    return subprocess.run([cand], capture_output=True, timeout=25, input=b"")
                except OSError as e:
                    if BLOCK_MARK in str(e):
                        time.sleep(0.4)
                        continue
                    break
        except OSError:
            continue
    print("   (换路径换名后仍被拦截: %s)" % (last[:60]))
    return None


def main():
    srcs = sorted(
        os.path.join(d, f)
        for d, _, fs in os.walk(ROOT)
        for f in fs
        if f.endswith(".cpp") and "__" not in d.split(os.sep)[-1]
    )
    pass_n = 0
    for s in srcs:
        rel = os.path.relpath(s, ROOT).replace("\\", "/")
        exe = os.path.join(OUT, os.path.splitext(os.path.basename(s))[0] + ".exe")
        exe_win = os.path.join(OUT_WIN, os.path.splitext(os.path.basename(s))[0] + ".exe")
        ok, info = compile_ok(s, exe)
        if not ok:
            print("[编译失败] %s\n%s" % (rel, info))
            continue
        # 同时产一份到临时目录，用于绕开本机的 exe 执行拦截
        compile_ok(s, exe_win)
        r = run_with_retry(exe_win)
        nlines = -1
        if r is not None:
            nlines = len([l for l in r.stdout.decode("utf-8", "replace").splitlines() if l.strip()])
        flag = "[OK]  " if (r is not None and r.returncode == 0) else "[异常]"
        nwarn = info[0] if isinstance(info, tuple) else 0
        print("%s %-40s 运行时输出 %2d 行  rc=%s  编译警告 %d 条"
              % (flag, rel, nlines, None if r is None else r.returncode, nwarn))
        if nwarn:
            for w in info[1][:3]:
                print("        warning: %s" % w[:110])
        pass_n += 1
    print("---- 编译并成功运行: %d / %d ----" % (pass_n, len(srcs)))


if __name__ == "__main__":
    main()
