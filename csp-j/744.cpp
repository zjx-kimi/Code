#include <bits/stdc++.h>
using namespace std;
const int Mod = 10007;
int n, ans, maxx;
int u, v;
int max1, max2 = 0;
int t1, t2;
vector<int> Edge[200010];
int arr[200010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        max1 = max2 = 0;
        t1 = t2 = 0;
        // ∑∑ij = (∑i)^2 - ∑i^2
        for (int j : Edge[i]) {
            if (arr[j] > max1)
                max2 = max1, max1 = arr[j];
            else if (arr[j] > max2)
                max2 = arr[j];
            t1 += arr[j], t2 += arr[j] * arr[j];
            t1 %= Mod, t2 %= Mod;
        }
        if (maxx < max1 * max2)
        	maxx = max1 * max2;
        ans = (t1 * t1 % Mod - t2 + ans + Mod) % Mod;
    }
    printf("%d %d\n", maxx, ans);
    return 0;
}