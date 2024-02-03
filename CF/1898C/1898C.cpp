#include <bits/stdc++.h>
using namespace std;
#define case true
#define endl '\n'
#define int long long
const int N = 3e5 + 10;
int t = 1;
int n, m, k;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (case)
    cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    if (n + m - 2 > k || (k - n - m + 2) % 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 1; i < m; i++)
      cout << (i & 1 ? "R" : "B") << ' ';
    cout << '\n';
    for (int i = 1; i < n; i++) {
      for (int i = 1; i < m; i++)
        cout << "R ";
      cout << '\n';
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= m; j++)
        cout << ((i & 1) ^ (m & 1) ? "B" : "R") << ' ';
      cout << '\n';
    }
  }
  return 0;
}
// ACed