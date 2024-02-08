#include <bits/stdc++.h>
using namespace std;
const int N = 255;
int n, m, sum;
int ans[N];
struct {
    int x, y;
} arr[N];
// 判断是否三点一线
bool check(int a, int b, int c) {
    return (arr[a].y - arr[b].y) * (arr[c].x - arr[b].x) ==
           (arr[c].y - arr[b].y) * (arr[a].x - arr[b].x);
}

int x(int a, int b) {
    return (arr[b].x - arr[a].x) * (a + 1) + (arr[a].y - arr[b].y) * (b + 1);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> arr[i].x >> arr[i].y;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (arr[i].y == arr[j].y)
                continue;
            int cnt = 0;
            for (int k = 1; k <= m; k++)
                if (check(i, j, k))
                    cnt++;
            if (1 <= x(i, j) && x(i, j) <= n)
                ans[x(i, j)] = max(ans[x(i, j)], cnt);
            cout << i << " " << j << " " << x(i, j) << endl;
        }
    }
    for (int i = 1; i <= n; i++)
        sum += ans[i];
    cout << sum << endl;
    return 0;
}