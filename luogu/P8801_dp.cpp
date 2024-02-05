#include <bits/stdc++.h>
using namespace std;
string n;
long long a, b, ans;
long long dp[20][105][105];
int main()
{
    cin >> n >> a >> b;
    n = " " + n;
    for (int i = 1; i < n.size(); i++)
    {
        for (int Ca = 0; Ca <= a; Ca++)
        {
            for (int Cb = 0; Cb <= b; Cb++)
            {
                for (int j = 0; j < 10 && Ca - j >= 0; j++)
                {
                    int go = (n[i] - '0' + j) % 10;
                    dp[i][Ca][Cb] = max(dp[i][Ca][Cb], dp[i - 1][Ca - j][Cb] * 10 + go);
                }
                for (int j = 0; j < 10 && Cb - j >= 0; j++)
                {
                    int go = (n[i] - '0' - j + 10) % 10;
                    dp[i][Ca][Cb] = max(dp[i][Ca][Cb], dp[i - 1][Ca][Cb - j] * 10 + go);
                }
                ans = max(ans, dp[i][Ca][Cb]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
给定一个正整数 N。你可以对 N 的任意一位数字执行任意次以下 2 种操作:

将该位数字加 1。如果该位数字已经是 9，加 1 之后变成 0。

将该位数字减 1。如果该位数字已经是 0，减 1 之后变成 9。

你现在总共可以执行 1 号操作不超过 A 次，2 号操作不超过 B 次。

请问你最大可以将 N 变成多少?
*/