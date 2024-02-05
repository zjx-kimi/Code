#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#define int long long
using namespace std;
const int N = 2e5 + 10;
int t, n, q, l, r;
int arr[N];
string s;
struct Tree
{
    int l, r, maxx, minn;
} tree[N << 2];
void build(int l, int r, int id)
{
    tree[id].l = l;
    tree[id].r = r;
    if (l == r)
    {
        tree[id].maxx = arr[l];
        tree[id].minn = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, id << 1);
    build(mid + 1, r, id << 1 | 1);
    tree[id].maxx = max(tree[id << 1].maxx, tree[id << 1 | 1].maxx);
    tree[id].minn = min(tree[id << 1].minn, tree[id << 1 | 1].minn);
    return;
}
inline int Maxx(int l, int r, int id)
{
    if (l > r)
        return INT_MIN;
    if (tree[id].r < l || r < tree[id].l)
        return INT_MIN;
    if (l <= tree[id].l && tree[id].r <= r)
        return tree[id].maxx;
    return max(Maxx(l, r, id << 1), Maxx(l, r, id << 1 | 1));
}
inline int Minn(int l, int r, int id)
{
    if (l > r)
        return INT_MAX;
    if (tree[id].r < l || r < tree[id].l)
        return INT_MAX;
    if (l <= tree[id].l && tree[id].r <= r)
        return tree[id].minn;
    return min(Minn(l, r, id << 1), Minn(l, r, id << 1 | 1));
}
signed main()
{
    scanf("%d", &t);
    while (t--)
    {
        // cin >> n >> q >> s;
        scanf("%d%d", &n, &q);
        s.resize(n);
        scanf("%s", s.c_str());
        s = " " + s;
        for (int i(1); (i - 1) ^ n; ++i)
            arr[i] = (s[i] == '+' ? 1 : -1);

        for (int i(1); (i - 1) ^ n; ++i)
            arr[i] += arr[i - 1];
        build(1, n, 1);
        while (q--)
        {
            scanf("%d%d", &l, &r);
            if (l == 1 && r == n)
            {
                puts("1");
            }
            else if (l == 1)
            {
                int L = Minn(r + 1, n, 1) - arr[r];
                int R = Maxx(r + 1, n, 1) - arr[r];
                int ans = R - L + 1;
                if (R < 0 || L > 0)
                    ans++;
                printf("%d\n", ans);
            }
            else if (r == n)
            {
                int L = Minn(1, l - 1, 1);
                int R = Maxx(1, l - 1, 1);
                int ans = R - L + 1;
                if (R < 0 || L > 0)
                    ans++;
                printf("%d\n", ans);
            }
            else
            {
                int L = min(Minn(1, l - 1, 1), Minn(r + 1, n, 1) - arr[r] + arr[l - 1]);
                int R = max(Maxx(1, l - 1, 1), Maxx(r + 1, n, 1) - arr[r] + arr[l - 1]);
                int ans = R - L + 1;
                if (R < 0 || L > 0)
                    ans++;
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}