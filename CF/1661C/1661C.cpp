#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 3e5 + 10;
int t, n, maxn;
int a[M];
inline int work(int maxn) {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; ++i) {
    cnt1 += (maxn - a[i]) % 2;
    cnt2 += (maxn - a[i]) / 2;
  }
  int tmp = cnt2 - cnt1;
  if (tmp >= 2)
    cnt1 += (tmp + 1) / 3 * 2, cnt2 -= (tmp + 1) / 3;
  if (cnt1 > cnt2)
    return cnt1 * 2 - 1;
  else
    return cnt2 * 2;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    maxn = 0;
    cin >> n;
    for (int i(1); i <= n; ++i) {
      cin >> a[i];
      maxn = max(maxn, a[i]);
    }
    cout << min(work(maxn), work(maxn + 1)) << '\n';
  }
  return 0;
}
// Aced