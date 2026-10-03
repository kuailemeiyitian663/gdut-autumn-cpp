/*
 * 06 函数
 * 一句话要点：值传递传的是副本（函数里改了外面不变），引用传递和指针传递能改外面；
 * 默认参数必须从右往左给（写了 b=10 就不能再给左边的 a 默认值）；
 * 同名函数参数不同 = 重载，编译器自己挑；递归要有能停下来的边界。
 */
#include <iostream>
using namespace std;

// 1. 值传递：外面不受影响
void addValue(int x) { x = x + 10; }

// 2. 引用传递：改的就是外面那个
void addRef(int& x) { x = x + 10; }

// 3. 指针传递：能改外面，还能传空指针做防御
void addPtr(int* p) { if (p) *p = *p + 10; }   // 先判空，防御野指针

// 4. 默认参数（从右往左）
int sum2(int a, int b = 10) { return a + b; }

// 5. 重载：同名函数，参数类型/个数不同
int max2(int a, int b) { return a > b ? a : b; }
double max2(double a, double b) { return a > b ? a : b; }

// 6. 递归：阶乘
long long fact(int n) { return n <= 1 ? 1 : n * fact(n - 1); }

// 7. 内联（小题量机试用不太上，知道就行）
inline int square(int x) { return x * x; }

int main() {
    int v = 5;

    addValue(v);
    cout << "值传递之后 v = " << v << "   <- 还是 5，函数里改的是副本" << endl;
    addRef(v);
    cout << "引用传递之后 v = " << v << "   <- 变成 15 了" << endl;
    addPtr(&v);
    cout << "指针传递之后 v = " << v << endl;

    cout << "sum2(3)     = " << sum2(3) << "        <- b 用默认值 10" << endl;
    cout << "sum2(3, 4)  = " << sum2(3, 4) << endl;

    cout << "max2(1, 2)    = " << max2(1, 2) << endl;
    cout << "max2(1.5, 2.0)= " << max2(1.5, 2.0) << "   <- 同一个名字，自动选 float 版" << endl;

    cout << "5! = " << fact(5) << endl;
    cout << "square(7) = " << square(7) << endl;

    return 0;
}
