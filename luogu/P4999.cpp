#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
long long t, l, r, len;
long long dp[20][200];
int a[20];
long long dfs(int id, int sum, bool limit)
{
    if (id == 0)
        return sum;
    if (dp[id][sum] >= 0 && limit == 0)
        return dp[id][sum];
    int bound = limit ? a[id] : 9;
    long long res = 0;
    for (int i = 0; i <= bound; i++)
    {  
        res += dfs(id - 1, sum + i, limit && i == bound);
        res %= Mod;
    }
    return limit == 0 ? dp[id][sum] = res : res;
}
long long solve(long long x)
{
    len = 0;
    while (x)
    {
        a[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, 0, 1);
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", (solve(r) - solve(l - 1) + Mod) % Mod);
    }
    return 0;
}