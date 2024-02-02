#include <bits/stdc++.h>
using namespace std;
#define case true
#define endl '\n'
#define int long long
const int N = 2e1 + 10;
int t = 1;
int n, s;
int arr[N], dp[N][2], minn[N], maxx[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (case)
    cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      if (2 * s >= arr[i]) {
        minn[i] = arr[i] - s;
        maxx[i] = s;
      } else {
        minn[i] = s;
        maxx[i] = max(0LL, arr[i] - s);
      }
    }
    dp[2][0] = arr[1] * minn[2], dp[2][1] = arr[1] * maxx[2];
    for (int i = 3; i < n; i++) {
      dp[i][0] = min(dp[i - 1][0] + maxx[i - 1] * minn[i],
                     dp[i - 1][1] + minn[i - 1] * minn[i]);
      dp[i][1] = min(dp[i - 1][0] + maxx[i - 1] * maxx[i],
                     dp[i - 1][1] + minn[i - 1] * maxx[i]);
    }
    cout << min(dp[n - 1][0] + maxx[n - 1] * arr[n],
                dp[n - 1][1] + minn[n - 1] * arr[n])
         << '\n';
  }
  return 0;
}
