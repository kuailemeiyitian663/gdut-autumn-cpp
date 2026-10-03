// =========================================================
// 机试坑 02：数组与字符串（sizeof 退化 / \0 收尾 / 越界）
// 对应考纲：数组、指针、运算符
// 编译运行：g++ -std=c++11 -Wall -o trap02 trap02-array-and-string.cpp
// =========================================================
#include <iostream>
#include <cstring>
using namespace std;

// 下面 countInFunction 里故意对"数组参数"做 sizeof，会触发这条警告。
// 这条警告本身就是考点（数组传参会退化成指针），所以定向屏蔽，别让 -Wall 刷屏。
#pragma GCC diagnostic ignored "-Wsizeof-pointer-div"
#pragma GCC diagnostic ignored "-Wsizeof-pointer-memaccess"

// 关键：数组一旦当参数传进函数，类型就退化成指针，sizeof 再也拿不到元素个数
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsizeof-pointer-div"
void countInFunction(int a[]) {
    cout << "  函数内部 sizeof(a) = " << sizeof(a)
         << "   -> 元素个数 = " << sizeof(a) / sizeof(a[0])
         << "   <- 这是错的！指针只有 8 字节" << endl;
}
#pragma GCC diagnostic pop

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    // ========== 坑 1：sizeof(数组)=字节数，sizeof(指针)=地址长度 ==========
    cout << "sizeof(arr)       = " << sizeof(arr) << "   <- 5 个 int，共 20 字节" << endl;
    cout << "sizeof(arr[0])    = " << sizeof(arr[0]) << "   <- 1 个 int，4 字节" << endl;
    cout << "元素个数 = sizeof(arr)/sizeof(arr[0]) = "
         << sizeof(arr) / sizeof(arr[0]) << endl;

    int* p = arr;                       // 退化成指针
    cout << "sizeof(p)         = " << sizeof(p)
         << "   <- 64 位下一个地址 8 字节，不是 20" << endl;

    cout << "把同一个数组传进函数：" << endl;
    countInFunction(arr);
    cout << "  正确做法：函数里另给一个参数 int n，把元素个数传进去" << endl;

    // ========== 坑 2：char 字符串靠 \0 结尾，两个长度差 1 ==========
    char s[] = "abc";
    cout << "strlen(s)         = " << strlen(s) << "   <- 3，数到 \\0 为止，不含它" << endl;
    cout << "sizeof(s)         = " << sizeof(s) << "   <- 4，把末尾的 \\0 也算进去了" << endl;

    // 自己开字符数组时，必须给 \0 留一个位置，否则输出会一直读到内存外面
    char buf[4] = {'a', 'b', 'c', 'd'};   // 四个都是有效字符，没有 \0
    // cout << buf << endl;                // 危险：printf/cout 会接着往后读，可能崩
    buf[3] = '\0';                        // 正确：手动补一个 \0 收尾
    cout << "补 \\0 之后 buf     = " << buf << endl;

    // ========== 坑 3：越界编译器不拦，越界写必崩 ==========
    int a[3] = {0, 0, 0};
    // a[3] = 99;                         // 越界写：大概率段错误，机试这题直接 0 分
    // int x = a[100];                    // 越界读：读到垃圾值，每次跑结果都不一样
    cout << "越界那两行已注释：" << endl;
    cout << "  看到 for (i = 0; i <= len; i++) 而不是 i < len，立刻警觉，改成 < " << endl;
    for (int i = 0; i < 3; i++) a[i] = i + 1;   // 正确：i < len
    cout << "正确循环赋值后 a[] = " << a[0] << "," << a[1] << "," << a[2] << endl;

    return 0;
}
