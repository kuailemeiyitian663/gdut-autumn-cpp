# gdut-autumn-cpp

广东工业大学 自动化 大一 · DynamicX（DX）机试备考作品仓
考纲八个点的独立小 Demo 合集，每个点一个能直接跑的 `.cpp`，README 只记一句话要点。

> 为什么要做这个仓：深圳 / 广州一带的嵌入式、机器人实习岗 JD 里反复写着
> "有完整嵌入式项目经历 / RoboMaster 等竞赛经验者优先"。
> 筛的是**能不能拿出代码**，不是成绩单上有多少分。
> 机试考完这批知识如果不留痕，两周后就归零；存成仓库，它才变成"作品"。

---

## 目录（按 DX 机试考纲顺序）

| # | 考纲点 | 文件 | 一句话 |
|---|--------|------|--------|
| 01 | 变量 | `01-basics/variables.cpp` | 四种基础类型、`const`、输入输出、未初始化就是垃圾值 |
| 02 | 流程控制 | `02-control/flow-control.cpp` | if / switch / for / while / break / continue，switch 漏 break 会穿透 |
| 03 | 类型转换 | `03-type-cast/type-cast.cpp` | 隐式转换、截断不是四舍五入、`ch - '0'`、整数除法掉小数点 |
| 04 | 运算符 | `04-operators/operators.cpp` | 自增自减前后置、`&&` 短路、三元、位运算、优先级 |
| 05 | 数组 / 指针 / 引用 | `05-array-pointer-ref/array-pointer-reference.cpp` | 数组名即首地址、指针步长按类型、`&` 引用是别名 |
| 06 | 函数 | `06-functions/functions.cpp` | 值传递 vs 引用传递、默认参数、重载、递归 |
| 07 | 类 / 继承 / 多态 | `07-oop/classes-polymorphism.cpp` | virtual 关键字、重写、动态绑定、纯抽象类 |
| 08 | vector | `08-stl/vector.cpp` | 增删遍历、二维 vector、排序去重、常用算法 |

---

## 怎么跑起来

### ✅ 状态：已在真机上编译 + 运行验证（2026-10-03）

- 装的是 **TDM-GCC 10.3.0（TDM-GCC 官方版），装在 `D:\TDM-GCC`**。
- 8 个文件**全部编译通过，全部成功运行**，开 `-Wall` 时**零 error、零 warning**。
- 验证方式：根目录 `_verify.py`（`python _verify.py`），它会重新编译 8 个文件、逐个跑一遍、把运行时输出行数打出来。
- 顺手修掉两个真会扣分的问题：
  1. `04-operators/operators.cpp` 原来把 `p++` 和 `p` 塞进同一条 `cout` —— 这是**未定义行为**（`<<` 的求值顺序没规定，有的编译器先算右边）。已拆成两句。
  2. `04-operators/operators.cpp` 的 `bool r` 声明了没用；补了一行输出。
- `01-basics/variables.cpp` 里留了一处**故意的** `-Wuninitialized` 演示（就是"不初始化 = 垃圾值"这个考点），用 `#pragma GCC diagnostic ignored` 定向关掉了，其余代码照常吃完整 `-Wall`。

**日常怎么跑**：双击根目录的 `run.bat`，8 个文件全编译一遍并依次运行，输出落 `build/`。
`run.bat` 会自动找 `g++`；如果 PATH 里没有，会回落到 `D:\TDM-GCC\bin\g++.exe`。

> 本机小坑（不是你代码的问题）：Windows 的"应用程序控制策略"会**随机**拦掉某个 exe 的执行，
> 报 `WinError 4551 应用程序控制策略已阻止此文件`。换个路径/换个名字重跑一般就好，`_verify.py` 里已经带自动重试。

### 三个免费的编译器（任选一个，都是开源免费）

**你已经装好的就是方案 A：TDM-GCC 10.3.0，路径 `D:\TDM-GCC\bin\g++.exe`。** 后续不用再装别的。

| 方案 | 状态 | 说明 |
|------|------|------|
| **A. TDM-GCC 10.3.0** | ✅ **已装，正在用** | 装在 `D:\TDM-GCC`。64-bit，约 100MB。C++11 全支持，机试够用 |
| **B. MSYS2 + VS Code** | ⏸ 暂不用 | DX 视觉线以后要上 OpenCV 再考虑。体积大、耗时长，现在装是拿时间换负资产 |
| **C. 在线编译器** | ⛔ 别用 | cpp.sh / coliru / godbolt 实测本机全连不上，白花时间 |

本机终端里跑单条：

```bash
# 方式 1：用完整路径（不用配 PATH，永远不会找错）
D:\TDM-GCC\bin\g++.exe -std=c++11 -Wall -o variables.exe variables.cpp
variables.exe

# 方式 2：把编译器加进 PATH，之后都能直接敲 g++
set PATH=D:\TDM-GCC\bin;%PATH%
g++ -std=c++11 -Wall -o variables.exe variables.cpp
```

> 别用 `D:\Dev-Cpp` 里那个自带编译器：它是 **gcc 4.9.2**（2014 年的），对 C++11 支持不全，会给你添假报错。

本地终端跑单条：

```bash
cd gdut-autumn-cpp/01-basics
g++ -std=c++11 variables.cpp -o variables.exe
variables.exe
```

**Dev-C++ / Code::Blocks / VS 的用户**：直接新建源文件 → 粘贴 → 编译运行，不用管命令行。


---

## 推到 GitHub（远端这一步现在还没做）

本机没法替你做：GitHub 连接器没授权、`gh` 没装。三行手打就行：

```bash
cd gdut-autumn-cpp
git remote add origin https://github.com/<你的用户名>/gdut-autumn-cpp.git
git branch -M main
git push -u origin main
```

仓库已经在本地建好了，第一次 commit 是 `2e656f5`。
**注意推之前先改掉 metadata**：`git config user.name` / `git config user.email` 现在是我代填的占位值，
推上去会变成你的提交作者，改一下再 push（本机：`git config user.email "你的邮箱"`）。

## 我的提交记录

- 找一份 README 说明为什么建这个仓（就是上面那段）
- 每个考纲点一个文件，一次一个 commit
- 最后一条：把机试真题/自己踩的坑补成 `09-traps/`

---

## 免责

这些 Demo 是**起点不是终点**。答应过自己的事：每个文件至少亲手改一行、加一句注释、跑出自己的结果，再 push。
交上去的代码如果连自己都说不清每一行在干嘛，那它就不是作品，是负债。


## VS Code 里怎么用（本机已配好）

编辑器装在 `D://Microsoft VS Code\Code.exe`，C/C++ 扩展（cpptools、cmake-tools、cpp-devtools）已装。

| 想干嘛 | 怎么操作 |
|--------|----------|
| 编译当前这个文件 | `Ctrl+Shift+B` → 用 D://TDM-GCC 的 g++ 编译，带 `-Wall -g`，产物同名 `.exe` 落在同目录 |
| 断点调试 | `F5` → gdb 调试（TDM-GCC 自带 gdb.exe），会自动先编译再启动 |
| 八个文件全量验收 | 终端里 `python _verify.py` → 全编译 + 全运行，打印每个文件输出行数 |

`.vscode/` 里三个文件是配好别删：

- `tasks.json` —— 两个任务：g++ 编译当前文件、全量验收
- `c_cpp_properties.json` —— IntelliSense 指向 D://TDM-GCC，代码补全和红色波浪线靠它
- `launch.json` —— gdb 调试配置，`preLaunchTask` 会先编译再调试

> 不想用 VS Code 也行，双击根目录 `run.bat`，同样全编译全运行。

> 编译器只用 `D://TDM-GCC//bin//g++.exe`。`D://Dev-Cpp//MinGW64` 里那个是 gcc 4.9.2（2014 年），会给你一堆假报错，别用。


## ⚠️ 本机网络：GitHub 网页打不开，但能推代码

实测（2026-10-05）：本机网络 **阻断 `github.com:443`**（网页和 HTTPS 推送都走这里），但 **SSH 通道是通的**（`github.com:22` 和 `ssh.github.com:443` 均可连）。

**所以推送必须走 SSH，不能用 HTTPS。** 本机 SSH 已配好（`~/.ssh/config` 把 github.com 指向 `ssh.github.com:443`），推送地址格式是：

```
git@github.com:<你的用户名>/gdut-autumn-cpp.git
```

完整的排查数据、加公钥步骤、Gitee 备选方案见工作区里的 **`怎么把代码推上GitHub.md`**。
