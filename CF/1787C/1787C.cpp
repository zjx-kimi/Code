#include <bits/stdc++.h>
using namespace std;
#define case true
#define endl '\n'
#define int long long
const int N = 2e5 + 10;
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
        maxx[i] = arr[i] - s;
      }
    }
	dp[2][1] = arr[1] * 
    for (int i = 1; i <= n; i++) {
    }
  }
  return 0;
}