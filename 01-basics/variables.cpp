/*
 * 01 变量
 * 一句话要点：int / double / char / bool 四种基础类型；const 声明后不能改；
 * 局部变量不初始化就是垃圾值（机试读垃圾值对答案会误导你自己）；
 * cin 读东西前最好先 cout 一句提示，不然屏幕上看不出程序卡在哪。
 */
#include <iostream>
using namespace std;

int main() {
    // 1. 四种基础类型
    int score = 87;
    double avg = 87.5;
    char grade = 'B';
    bool passed = true;

    cout << "score=" << score << endl;
    cout << "avg=" << avg << endl;
    cout << "grade=" << grade << endl;
    cout << "passed=" << passed << endl;   // bool 打印出来是 1 / 0，不是 true / false

    // 2. 未初始化 = 垃圾值（只演示，实际写代码千万别这样）
    // -Wuninitialized 是 -Wall 的默认检查，故意留这一处：它就是要你看警告长什么样。
    // 下面这行 pragma 只在这一句里关掉它，其余代码照样吃 -Wall 的完整检查。
    int uninitialized;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
    cout << "未初始化的值: " << uninitialized << "  —— 每次跑可能不一样" << endl;
#pragma GCC diagnostic pop

    // 3. const 常量：声明之后不能再赋值
    const int MAX_STU = 50;
    // MAX_STU = 60;   // 这行编译不过，编译期就拦你
    cout << "MAX_STU=" << MAX_STU << endl;

    // 4. 输入输出
    int input;
    cout << "请输入一个整数: ";
    cin >> input;
    cout << "你输入的是: " << input << endl;

    return 0;
}
