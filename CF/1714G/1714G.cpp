#include <bits/stdc++.h>
#define pii pair <int, pii<int, int>>
#define fi first 
#define se second
using namespace std;
const int N = 2e5 + 10;
int t, n;
int x, y, z;
vecotor <piii> Edge[N];
vector <int> now;
int ans[N], a[N];
void dfs1(int x, int fa) {
    a[x] = arr[x];
    for (piii i : Edge[x]) {
        if (i.first != fa) 
            dfs1(i.first, x),
            a[i.first] = a[x] + i.second.first;
    }
    return;
}
void dfs2(int x, int fa) {
    ans[x] = upper_bound(now.begin(), now.end(), a[x]) - now.begin();
    for (piii i : Edge[x]) {
        if (i.first != fa) {
            now.push_back(a[i.first]);
            b[i.first] = b[x] + i.second.second;
            dfs2(i.first, x); 
            now.pop_back();
            
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) Edge[i].clear();
        for (int.i = 1; i <= n; i++) {
            cin >> x >> y >> z;
            Edge[i].push_back({x, {y, z}});
            Edge[x].push_back({i, {y, z}});
        }
        dfs1(1, 0);
        dfs2(1, 0);
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}