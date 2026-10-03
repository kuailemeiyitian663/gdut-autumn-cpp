/*
 * 02 流程控制
 * 一句话要点：if / else if / else 按区间判断；switch 每一档都要写 break，
 * 漏一个就会"穿透"到下一档一起执行；break 跳出整个循环、continue 只跳过本次。
 */
#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "输入成绩(0-100): ";
    cin >> score;

    // 1. if / else if：按区间往下落
    if (score >= 90) cout << "A" << endl;
    else if (score >= 80) cout << "B" << endl;
    else if (score >= 60) cout << "C" << endl;
    else cout << "D" << endl;

    // 2. switch：注意 case 10 和 case 9 写在一起是"共用一档"
    int level = score / 10;   // 90 分 -> 9
    switch (level) {
        case 10:
        case 9:  cout << "switch: 优秀" << endl; break;
        case 8:  cout << "switch: 良好" << endl; break;
        case 7:
        case 6:  cout << "switch: 及格" << endl; break;
        default: cout << "switch: 不及格" << endl; break;
    }
    // 如果 case 9 那档忘了 break，它接着往下跑 case 8，屏幕上会连打两行

    // 3. for 累加
    int n, sum = 0;
    cout << "求 1..n 的和，n=";
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    cout << "1.." << n << " 的和 = " << sum << endl;

    // 4. while + break：找到第 3 个 7 的倍数就停
    int i = 1, cnt = 0;
    while (i <= 100) {
        if (i % 7 == 0) cnt++;
        if (cnt >= 3) break;      // break 直接跳出整个 while
        i++;
    }
    cout << "第 3 个 7 的倍数是 " << i << endl;

    // 5. continue：打印 1..20 里所有奇数
    cout << "1..20 的奇数: ";
    for (int j = 1; j <= 20; j++) {
        if (j % 2 == 0) continue;  // continue 只跳过本次，循环继续
        cout << j << " ";
    }
    cout << endl;

    return 0;
}
