#include <bits/stdc++.h>
using namespace std;
#define case true
#define endl '\n'
#define int long long
const int N = 4005;
int t, n, last, Find, arr[N], sz[N], cnt;
bool dp[N], vis[N];
signed main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
	if (case)
		cin >> t;
  	while (t--) {
		cin >> n;
		for (int i = 1; i <= n * 2; i++) {  
		  cin >> arr[i];
		}
		last = Find = n * 2;
		cnt = 0;			
		for (int i = 1; i <= 2 * n; i++) vis[i] = 0;
		for (int i = n * 2; i >= 1; i--) {
			vis[arr[i]] = 1;
			if (arr[i] != Find)
				continue;
			sz[++cnt] = last - i + 1, last = i - 1;
			while (Find && vis[Find])
				Find--;
		}
		dp[0] = 1;
		for (int i = 1; i <= 2 * n; i++) dp[i] = 0;
		for (int i = 1; i <= cnt; i++) 
			for (int j = n; j >= sz[i]; j--) 
			    dp[j] |= dp[j - sz[i]];
		cout << (dp[n] ? "YES" : "NO") << '\n';
  }
  return 0;
}
// ACed