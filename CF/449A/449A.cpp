/*
给出一个N * M的矩阵，给K个操作，每次操作可以横/竖切割矩阵，最后求K次切割之后，矩阵最小的那块面积最大是多少？

输入输出样例
输入 #1复制
3 4 1
输出 #1复制
6
输入 #2复制
6 4 2
输出 #2复制
8
输入 #3复制
2 3 4
输出 #3复制
-1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k;
int main() {
    cin >> n >> m >> k;
    if (k > n + m - 2) {
        cout << "-1";
        return 0;
    }
    if (k < m) {
        if (k < n) {
            cout << max(n * (m / (k + 1)), m * (n / (k + 1)));
        } else {
            cout << max(n * (m / (k + 1)), m / (k - n + 2));
        }
    } else {
        if (k < n) {
            cout << max(n / (k - m + 2), m * (n / (k + 1)));
        } else {
            cout << max(n / (k - m + 2), m / (k - n + 2));
        }
    }
    return 0;
}