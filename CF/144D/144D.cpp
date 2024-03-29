#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int x[N], y[N], w[N], dis[N];
int n, s, m, l, ans;
struct Node
{
    int first, second;
    bool operator<(const Node o) const
    {
        return second > o.second;
    }
};
vector<Node> edge[N];
priority_queue<Node> q;
bool v[N];
signed main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i] >> w[i];
        edge[x[i]].push_back({y[i], w[i]});
        edge[y[i]].push_back({x[i], w[i]});
    }
    dis[s] = 0;
    q.push({s, 0});
    while (q.size())
    {
        int u = q.top().first;
        q.pop();
        if (v[u])
            continue;
        v[u] = 1;
        for (int i = 0; i < edge[u].size(); i++)
        {
            if (dis[edge[u][i].first] > dis[u] + edge[u][i].second)
            {
                dis[edge[u][i].first] = dis[u] + edge[u][i].second;
                q.push({edge[u][i].first, dis[edge[u][i].first]});
            }
        }
    }
    cin >> l;
    for (int i = 1; i <= n; i++)
        ans += (dis[i] == l);
    for (int i = 1; i <= m; i++)
    {
        if (dis[x[i]] + w[i] - l + dis[y[i]] == l && dis[y[i]] < l && dis[x[i]] < l)
        {
            ans++;
            continue;
        }
        if (dis[x[i]] + w[i] - l + dis[y[i]] > l && dis[x[i]] < l)
            ans++;
        if (dis[x[i]] + w[i] - l + dis[y[i]] > l && dis[y[i]] < l)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}
// ACed