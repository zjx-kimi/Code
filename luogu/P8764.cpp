#include <bits/stdc++.h>
using namespace std;
long long n, k, f[100][100][2];
int a[100], len;
long long dfs(int w, long long cnt, bool limit)
{
    if (f[w][cnt][limit] != -1)
        return f[w][cnt][limit];
    if (w == 0)
        return cnt == k;
    f[w][cnt][limit] = 0;
    for (long long i = 0; i <= (limit ? a[w] : 1); ++i)
        f[w][cnt][limit] += dfs(w - 1, cnt + i, limit & i == a[w]);
    return f[w][cnt][limit];
}
long long solve(long long x)
{
    memset(f, -1, sizeof(f));
    len = 0;
    while (x)
        a[++len] = x % 2, x /= 2;
    return dfs(len, 0, 1);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cout << solve(n);
    return 0;
}
// ACed