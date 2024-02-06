#include <bits/stdc++.h>
using namespace std;
long long t, l, r, len;
long long dp[20][200][2][2];
int a[20];
long long dfs(int id, int last, bool limit, bool zero)
{
    if (id == 0)
        return 1;
    if (dp[id][last][limit][zero] >= 0)
        return dp[id][last][limit][zero];
    int bound = limit ? a[id] : 9;
    long long res = 0;
    for (int i = 0; i <= bound; i++)
    {
        if (abs(i - last) <= 1 && !zero)
            continue;
        res += dfs(id - 1, i, limit && i == bound, zero && i == 0);
    }
    return dp[id][last][limit][zero] = res;
}
long long solve(long long x)
{
    memset(dp, -1, sizeof(dp));
    len = 0;
    while (x)
    {
        a[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, -2, 1, 1);
}
signed main()
{
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
    return 0;
}
/*
不含前导零且相邻两个数字之差至少为 2 的正整数被称为 windy 数。windy 想知道，在 a 和 b 之间，包括 a 和 b ，总共有多少个 windy 数？
*/