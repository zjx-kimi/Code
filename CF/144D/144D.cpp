#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 10;
int x[N], y[N], w[N];
int dis[N], n, s, m;
vector<pii> edge[N];
priority_queue<pii> q;
bool v[N];
signed main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    for (int i = 1; i <= m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        x[i] = u, y[i] = v, w[i] = d;
        edge[u].push_back((node) {
            v, d });
        edge[v].push_back((node) {
            u, d });
    }
    dis[s] = 0;
    q.push((node) {
        s, 0 });
    while (q.size()) {
        int u = q.top().to;
        q.pop();
        if (v[u]) continue;
        v[u] = 1;
        for (int i = 0; i < edge[u].size(); i++) {
            if (dis[edge[u][i].to] > dis[u] + edge[u][i].v) {
                dis[edge[u][i].to] = dis[u] + edge[u][i].v;
                q.push((node) {
                    edge[u][i].to, dis[edge[u][i].to] });
            }
        }
    }
    int cnt = 0, l;
    cin >> l;
    for (int i = 1; i <= n; i++) {
        cnt += (dis[i] == l);
    }
    for (int i = 1; i <= m; i++) {
        if (dis[x[i]] + w[i] - l + dis[y[i]] == l && dis[y[i]] < l && dis[x[i]] < l) {
            //			cout<<"case 1: "<<i<<"\n";
            cnt++;
            continue;
        }
        if (dis[x[i]] + w[i] - l + dis[y[i]] > l && dis[x[i]] < l) {
            //			cout<<"case 2: "<<i<<"\n";
            cnt++;
        }
        if (dis[x[i]] + w[i] - l + dis[y[i]] > l && dis[y[i]] < l) {
            //			cout<<"case 3: "<<i<<"\n";
            cnt++;
        }
    }
    cout << cnt << "\n";
}