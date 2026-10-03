// =========================================================
// 机试坑 03：类 / 继承 / 多态（对象切片 + 析构必须虚）
// 对应考纲：类、继承、多态
// 编译运行：g++ -std=c++11 -Wall -o trap03 trap03-object-slicing.cpp
// =========================================================
#include <iostream>
using namespace std;

// ============ 坑 1：对象切片（考多态必踩）============
class Worker {
public:
    int id;
    // 基类有虚函数，才能谈多态；没有的话下面引用传参也不会动态绑定
    virtual void work() { cout << "Worker 干活" << endl; }
};

class Programmer : public Worker {
public:
    int skill;                                   // 派生类自己多出来的成员
    void work() { cout << "Programmer 写代码" << endl; }
};

// ============ 坑 2：基类析构不加 virtual，delete 基类指针会漏 ============
class OldDevice {
public:
    ~OldDevice() { cout << "  OldDevice 析构" << endl; }      // 非虚
};
class NewDevice : public OldDevice {
public:
    ~NewDevice() { cout << "  NewDevice 析构" << endl; }
};

int main() {
    // ---- 切片：派生对象赋给基类，派生多出来的部分被直接切掉 ----
    Programmer p;
    p.id = 1;
    p.skill = 100;

    Worker w = p;             // 复制时只搬 Worker 那一块，skill 没了
    cout << "w.id    = " << w.id << endl;
    // cout << w.skill << endl;   // 编译报错：w 这个对象里压根没 skill 这个成员
    w.work();                  // 输出 "Worker 干活"，不是 Programmer

    cout << "（为什么？赋值是逐字节拷贝，但赋值完还会把虚表指针还原成基类的）" << endl;
    cout << "正确做法：用基类的引用或指针接，别用基类值接" << endl;
    Worker& rw = p;            // 引用，不拷贝
    rw.work();                 // 输出 "Programmer 写代码" —— 这才是真多态

    // ---- 析构：基类析构非虚，delete 基类指针时派生析构被吞 ----
    cout << "delete 一个 NewDevice 对象，但用 OldDevice* 接：" << endl;
    OldDevice* op = new NewDevice();
    delete op;                 // 只打印 OldDevice 析构，NewDevice 析构被跳过

    cout << "正确做法：~OldDevice() 前面加 virtual，两个都会打印" << endl;
    cout << "（配套铁律：只要类里有 virtual 函数，析构函数就必须写 virtual）" << endl;

    return 0;
}
