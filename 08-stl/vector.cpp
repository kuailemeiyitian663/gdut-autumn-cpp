/*
 * 08 vector（考纲里唯一一个 STL）
 * 一句话要点：vector 就是"能自动扩容的数组"，用下标 [] 访问、push_back 追加、size 取长度；
 * 遍历三件套：下标 / 迭代器 / 范围 for；二维用 vector<vector<int> >，注意老编译器要空格防 ">>"；
 * 排序去重固定三连：sort -> unique -> erase。
 */
#include <iostream>
#include <vector>
#include <algorithm>   // sort, find, unique
#include <numeric>     // accumulate
using namespace std;

int main() {
    // 1. 三种构造
    vector<int> a;                          // 空的
    vector<int> b(5);                       // 5 个 0
    vector<int> c = {1, 2, 3, 4, 5};        // 初始化列表（C++11）

    // 2. 增删
    a.push_back(10);
    a.push_back(20);
    a.insert(a.begin(), 5);                 // 头部插入
    a.erase(a.begin());                     // 删掉开头那个 5
    a.pop_back();                           // 删掉末尾
    cout << "a 的元素: ";
    for (int i = 0; i < (int)a.size(); i++) cout << a[i] << " ";
    cout << endl;

    // 3. size / empty
    cout << "a.size = " << a.size() << "   a.empty = " << a.empty() << endl;

    // 4. 三种遍历
    cout << "下标遍历:  ";
    for (size_t i = 0; i < c.size(); ++i) cout << c[i] << " ";
    cout << endl;

    cout << "迭代器:    ";
    for (vector<int>::iterator it = c.begin(); it != c.end(); ++it) cout << *it << " ";
    cout << endl;

    cout << "范围 for:  ";
    for (int v : c) cout << v << " ";
    cout << endl;

    // 5. 二维 vector（画矩阵、存邻接表都很常用）
    int n = 3;
    vector<vector<int> > mat(n, vector<int>(n, 0));   // 3x3 全 0，注意那个空格
    mat[1][1] = 9;
    cout << "mat[1][1] = " << mat[1][1] << endl;

    // 6. 排序 + 去重三连
    vector<int> d = {4, 2, 9, 2, 7};
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    cout << "排好序去重: ";
    for (int v : d) cout << v << " ";
    cout << endl;

    // 7. 常用算法
    cout << "求和 = " << accumulate(d.begin(), d.end(), 0) << endl;
    cout << "9 在不在里面? " << (find(d.begin(), d.end(), 9) != d.end()) << endl;

    return 0;
}
