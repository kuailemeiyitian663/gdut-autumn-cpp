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

### ⚠️ 先说清楚状态

- 这 8 个文件**已经人工逐行复核过**（创建于 2026-10-03，之后改过一次注释），**但还没经过真实编译器**。
- 本机编译环境：git 有，`g++` / `clang++` 都没有，`gh` 没装，GitHub 连接器未授权。
- 所以你第一次跑如果遇到报错，**不是你抄错了，是环境没配好**——先看报错行号，把报错整段贴给我，我改。

**装了编译器之后**：双击根目录的 `run.bat`，8 个文件会全编译一遍并依次运行，输出落在 `build/` 里。`-Wall` 开着，有 warning 我会标出来。

### 三个免费的编译器（任选一个，都是开源免费）

| 方案 | 怎么装 | 适合谁 | 备注 |
|------|--------|--------|------|
| **A. TDM-GCC**（推荐） | 官网 <https://jmeubank.github.io/tdm-gcc/> 下安装包，一路 Next，勾 "Add to PATH" | 只想快点跑起来、不想折腾 | 约 100MB，64-bit。装完重启终端，敲 `g++ --version` 出版本号就成了 |
| **B. MSYS2 + VS Code** | 官网 <https://www.msys2.org/> 下安装包 → 装完打开 MSYS2 UCRT64 → `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-gcc` | 想正经搭 C++ 开发环境（DX 视觉线以后还要用） | 体积大、耗时长，但一步到位，往后 OpenCV 也能用 |
| **C. 在线编译器** | 用浏览器开 <https://www.onlinegdb.com/> ，粘代码点 Run | 只想临时看一眼结果 | **实测 cpp.sh 在本机网络下连不上**，别把时间花在那儿；onlinegdb 是否通看你自己的网 |

> 别选"Dev-C++"：它虽然一键，但自带的老编译器对 C++11 支持不全，容易给你添假报错。

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
