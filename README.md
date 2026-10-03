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

**方式 A（推荐，零安装）**：打开 <https://cpp.sh> 或 <https://www.onlinegdb.com/> ，把 `.cpp` 内容整段粘进左边代码框，点 Run。所有 Demo 都是 C++11 兼容，在线编译器直接能过。

**方式 B（本地）**：装一个免费开源的 TDM-GCC（<https://jmeubank.github.io/tdm-gcc/> ，约 100MB，选 64-bit），装完在终端里：

```bash
# 进入本目录（Windows 上把路径换成你自己的）
cd gdut-autumn-cpp/01-basics
g++ variables.cpp -o variables.exe
variables.exe
```

**Dev-C++ / Code::Blocks / VS 的用户**：直接新建源文件 → 粘贴 → 编译运行，不用管命令行。

---

## 我的提交记录

- 找一份 README 说明为什么建这个仓（就是上面那段）
- 每个考纲点一个文件，一次一个 commit
- 最后一条：把机试真题/自己踩的坑补成 `09-traps/`

---

## 免责

这些 Demo 是**起点不是终点**。答应过自己的事：每个文件至少亲手改一行、加一句注释、跑出自己的结果，再 push。
交上去的代码如果连自己都说不清每一行在干嘛，那它就不是作品，是负债。
