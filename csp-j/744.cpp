#include <bits/stdc++.h>
using namespace std;
int n, ans, maxx;
int u, v;
vector<int> Edge[100010];
int arr[100010]
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
        int max1 = 0, max2 = 0;  
        int t1 = 0, t2 = 0;      
        for (int j : Edge[i]) {
            if (w[j] > max1)
                max2 = max1, max1 = w[j];
            else if (w[j] > max2)
                max2 = w[j];
            t1 = (t1 + w[j]) % 10007;
            t2 = (t2 + w[j] * w[j]) % 10007;
        }
        t1 = t1 * t1 % 10007;
        ans = (ans + t1 + 10007 - t2) % 10007;
        if (maxx < max1 * max2)
            maxx = max1 * max2;
    }
    printf("%d %d\n", maxx, ans);
    return 0;
}
