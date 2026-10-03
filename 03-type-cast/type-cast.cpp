/*
 * 03 类型转换
 * 一句话要点：double 转 int 是直接截断（3.99 变 3，不是四舍五入）；
 * 字符 '5' 转数字要减 '0'；整数除以整数只留整数部分（5/2=2，不是 2.5）。
 */
#include <iostream>
using namespace std;

int main() {
    // 1. 隐式转换（小类型 -> 大类型，安全，编译器自动做）
    int a = 7;
    double b = a;               // int -> double
    cout << "a=" << a << "  b=" << b << endl;

    // 2. 精度丢失（大类型 -> 小类型，机试最爱考）
    double c = 3.99;
    int d = c;                  // 直接截断
    cout << "c=" << c << " -> d=" << d << "   3.99 变 3 了，不是 4" << endl;

    // 3. 显式转换三种写法（机试三种都可能出现）
    double e = 9.8;
    int f1 = (int)e;                    // C 风格
    int f2 = int(e);                    // 函数风格
    int f3 = static_cast<int>(e);       // C++ 写法，推荐
    cout << f1 << " " << f2 << " " << f3 << endl;

    // 4. 字符和数字之间
    char ch = '5';
    int num = ch - '0';         // 字符转数字：减 '0'
    cout << "ch=" << ch << "  num=" << num << endl;

    char big = 'A';
    cout << "'A' 的 ASCII = " << (int)big << endl;   // 字符 -> ASCII 码

    // 5. 整数除法陷阱（高频坑）
    int x = 5, y = 2;
    cout << "5/2   = " << x / y << "        <- 整数除整数，得 2" << endl;
    cout << "5.0/2 = " << 5.0 / y << "      <- 只要有一个是浮点就正常" << endl;

    // 6. 布尔转换：0 为 false，非 0 为 true
    cout << "(bool)0   = " << (bool)0 << endl;
    cout << "(bool)42  = " << (bool)42 << endl;

    return 0;
}
