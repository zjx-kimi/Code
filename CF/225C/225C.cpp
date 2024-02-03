#include <bits/stdc++.h>
#define int long long
using namespace std;	
const int N = 1005;
int n, m, a, b, ans = INT_MAX;
int sum[N];
int dp[2][2][N];
char c;
signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> c,
			sum[j] += (c == '#');
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 1; j++)
			for (int k = 1; k <= b; k++)
				dp[i][j][k] = INT_MAX;
	dp[1][0][1] = sum[1]; 
	dp[1][1][1] = n - sum[1];
	for (int I = 2; I <= m; I++) {
		int i = I & 1;
		/*solve dp[I][0/1][1]*/
		dp[i][0][1] = dp[i][1][1] = INT_MAX;
		for (int j = a; j <= b; j++) 
			dp[i][0][1] = min(dp[1 - i][1][j] + sum[I], dp[i][0][1]),
			dp[i][1][1] = min(dp[1 - i][0][j] + n - sum[I], dp[i][1][1]);
		/*solved dp[I][0/1][1]*/

		for (int j = 2; j <= b; j++) {
			dp[i][0][j] = dp[1 - i][0][j - 1] + sum[I];
			dp[i][1][j] = dp[1 - i][1][j - 1] + n - sum[I];
		}
	}
	for (int i = a; i <= b; i++)
		ans = min(ans, min(dp[m & 1][0][i], dp[m & 1][1][i]));
	cout << ans;
	return 0;
}