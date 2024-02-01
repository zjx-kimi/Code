#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int t, n;
struct node {
    int a, d;
    int pre, nxt;
} Arr[N];
set<int> a; // 在这一轮中有可能死的。
set<int> b; // 在这一轮中死的。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i < n; i++) Arr[i].nxt = i + 1; Arr[n].nxt = 1;
        for (int i = 2; i <= n; i++) Arr[i].pre = i - 1; Arr[1].pre = n;
        for (int i = 1; i <= n; i++) cin >> Arr[i].a;
        for (int i = 1; i <= n; i++) cin >> Arr[i].d;
        for (int i = 1; i <= n; i++) a.insert(n);
        for (int i = 1; i <= n; i++) {
            for (int i : a) { // 检查每一个有可能死的人

            }
        }
    }
}