#include <bits/stdc++.h>
using namespace std;
const int Mod = 10007;
int n, ans, maxx;
int u, v;
int max1, max2 = 0;
int t1, t2;
vector<int> Edge[100010];
int arr[100010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        Edge[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        max1 = max2 = 0;
        t1 = t2 = 0;
        // ∑∑ij = (∑i)^2 - ∑i^2
        for (int j : Edge[i]) {
            if (w[j] > max1)
                max2 = max1, max1 = w[j];
            else if (w[j] > max2)
                max2 = w[j];
            t1 = (t1 + w[j]) % Mod;
            t2 = (t2 + w[j] * w[j]) % Mod;
        }
        if (maxx < max1 * max2)
            t1 = t1 * t1 % Mod;
        ans += t1 - t2;
        ans = (ans + Mod) % Mod;
        maxx = max1 * max2;
    }
    printf("%d %d\n", maxx, ans);
    return 0;
}
