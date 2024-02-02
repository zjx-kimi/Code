#include <bits/stdc++.h>
using namespace std;
const int N = 3e1 + 10;
int t, n;
struct node
{
    int a, d;
    int pre, nxt;
} Arr[N];
set <int> a; // 在这一轮中有可能死的。
set <int> b; // 在这一轮中死的。
bool l[N];  // 判断死了没死。
void build()
{
    int last = -1;
    for (int i = 1; i <= n; i++)
        if (l[i] == 1)
        {
            last = i;
            break;
        }
    for (int now = last + 1; now <= n; now++)
        if (l[now])
            Arr[now].pre = last,
            Arr[last].nxt = now,
            last = now;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        a.clear();
        cin >> n;
		for (int i = 1; i <= n; i++) l[i] = 1; // 都活着。
		Arr[n].nxt = 0;
        build();
        for (int i = 1; i <= n; i++) cin >> Arr[i].a;
        for (int i = 1; i <= n; i++) cin >> Arr[i].d;
        for (int i = 1; i <= n; i++) a.insert(i);
        for (int i = 1; i <= n; i++)
        {
            b.clear();
            for (int i : a)
            { // 检查每一个有可能死的人
                node now = Arr[i];
                if (Arr[now.pre].a + Arr[now.nxt].a > now.d) // 死了。
                    b.insert(i), l[i] = 0;
            }
            cout << b.size() << ' ';
            a.clear();
            // 如果这一轮，你没有死，你的左右两边的人也没死，那么下一轮你也不会死。
            for (int i : b)
            { // 枚举每一个死了的人，把他左右两边的人判为有可能死的。
                if (l[Arr[i].pre])
                    a.insert(Arr[i].pre);
                if (l[Arr[i].nxt]) 
					a.insert(Arr[i].nxt);
            }
            build(); // 重新构建列表。
        }
        cout << '\n';
    }
}
// WA