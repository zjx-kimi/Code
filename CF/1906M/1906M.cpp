#include <bits/stdc++.h>
using namespace std;
#define case false
#define endl '\n'
#define int long long
const int N = 3e5 + 10;
int t = 1;
int n, maxx, sum;
int arr[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (case)
    cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> arr[i], maxx = max(maxx, arr[i]), sum += arr[i];
    if ((sum - maxx) * 2 < maxx) {
      cout << sum - maxx << '\n';
    } else {
      cout << sum / 3;
    }
  }
  return 0;
}
// ACed