#include <bits/stdc++.h>
using namespace std;
string n;
long long a, b, ans;
long long dp[20][105][105];
void dfs(int id, int A, int B, long long number)
{
    if (id >= n.size())
    {
        ans = max(ans, number);
        return;
    }
    if (dp[id][A][B] > number)
        return;
    dp[id][A][B] = number;
    for (int i = 9; i >= 0; --i)
    {
        int Acost = (i - n[id] + '0' + 10) % 10;
        int Bcost = (n[id] - '0' - i + 10) % 10;
        bool flag = 1;
        if (Acost <= A)
        {
            flag = 0;
            dfs(id + 1, A - Acost, B, number * 10 + i);
        }
        if (Bcost <= B)
        {
            flag = 0;
            dfs(id + 1, A, B - Bcost, number * 10 + i);
        }
        if (!flag)
            break;
    }
}
int main()
{
    cin >> n >> a >> b;
    n = " " + n;
    dfs(1, a, b, 0);
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