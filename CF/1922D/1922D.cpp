#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
int t, n;
int a[N], d[N];
int pre[N], nxt[N];
set<int> A; // 在这一轮中有可能死的。
set<int> b; // 在这一轮中死的。
bool l[N];  // 判断死了没死。
void build() {
  int last = -1;
  for (int i = 1; i <= n; i++)
    if (l[i] == 1) {
      last = i;
      break;
    }
  for (int now = last + 1; now <= n; now++)
    if (l[now])
      pre[now] = last, nxt[last] = now, last = now;
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    A.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
      l[i] = 1; // 都活着。
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++)
      cin >> d[i];
    for (int i = 1; i <= n; i++)
      A.insert(i);
    for (int i = 1; i <= n; i++)
      pre[i] = i - 1;
    for (int i = 1; i <= n; i++)
      nxt[i] = i + 1;
    pre[1] = nxt[n] = 0;
    for (int i = 1; i <= n; i++) {
      b.clear();
      for (int i : A) {                   // 检查每一个有可能死的人
        if (a[pre[i]] + a[nxt[i]] > d[i]) // 死了。
          b.insert(i), l[i] = 0;
      }
      cout << b.size() << ' ';
      A.clear();
      // 如果这一轮，你没有死，你的左右两边的人也没死，那么下一轮你也不会死。
      for (int i : b) {
        pre[nxt[i]] = pre[i];
        nxt[pre[i]] = nxt[i];
        if (l[pre[i]])
          A.insert(pre[i]);
        if (l[nxt[i]])
          A.insert(nxt[i]);
      }
    }
    cout << '\n';
  }
}
// ACed