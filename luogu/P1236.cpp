#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
struct node {
    int a, b;
    char c;
};
vector<node> ans;
void dfs(int n, int a, int b, int c, int d) {
    cout << n << " " << a << " " << b << " " << c << " " << d << endl;
    if (n == 1) {
        if (a == 24) {
            for (int i = 1; i <= 3; i++) {
                cout << ans[i].a << ans[i].c << ans[i].b;
                if (ans[i].c == '+')
                    cout << "=" << ans[i].a + ans[i].b;
                else if (ans[i].c == '-')
                    cout << "=" << ans[i].a - ans[i].b;
                else if (ans[i].c == '*')
                    cout << "=" << ans[i].a * ans[i].b;
                else
                    cout << "=" << ans[i].a / ans[i].b;
                cout << endl;
            }
            exit(0);
        }
        return;
    }
    if (n == 2) {
        ans[3] = {max(a, b), min(a, b), '+'};
        dfs(1, a + b, 0, 0, 0);
        ans[3] = {a, b, '-'};
        dfs(1, a - b, 0, 0, 0);
        ans[3] = {b, a, '-'};
        dfs(1, b - a, 0, 0, 0);
        ans[3] = {max(a, b), min(a, b), '*'};
        dfs(1, a * b, 0, 0, 0);
        if (b && a % b == 0)
            ans[3] = {a, b, '/'}, dfs(1, a / b, 0, 0, 0);
        if (a && b % a == 0)
            ans[3] = {b, a, '/'}, dfs(1, b / a, 0, 0, 0);
    }
    if (n == 3) {
        ans[2] = {a, b, '+'};
        dfs(2, a + b, c, 0, 0);
        ans[2] = {a, b, '-'};
        dfs(2, a - b, c, 0, 0);
        ans[2] = {b, a, '-'};
        dfs(2, b - a, c, 0, 0);
        ans[2] = {a, b, '*'};
        dfs(2, a * b, c, 0, 0);
        if (b && a % b == 0)
            ans[2] = {a, b, '/'}, dfs(2, a / b, c, 0, 0);
        if (a && b % a == 0)
            ans[2] = {b, a, '/'}, dfs(2, b / a, c, 0, 0);
        ans[2] = {a, c, '+'};
        dfs(2, a + c, b, 0, 0);
        ans[2] = {a, c, '-'};
        dfs(2, a - c, b, 0, 0);
        ans[2] = {c, a, '-'};
        dfs(2, c - a, b, 0, 0);
        ans[2] = {a, c, '*'};
        dfs(2, a * c, b, 0, 0);
        if (c && a % c == 0)
            ans[2] = {a, c, '/'}, dfs(2, a / c, b, 0, 0);
        if (a && c % a == 0)
            ans[2] = {c, a, '/'}, dfs(2, c / a, b, 0, 0);
        // ans[2] = {b, c, '+'};
        // dfs(2, b + c, a, 0, 0);
        // ans[2] = {b, c, '-'};
        // dfs(2, b - c, a, 0, 0);
        // ans[2] = {c, b, '*'};
        // dfs(2, c * b, a, 0, 0);
        // if (c && b % c == 0)
        //     ans[2] = {b, c, '/'}, dfs(2, b / c, a, 0, 0);
        // if (b && c % b == 0)
        //     ans[2] = {c, b, '/'}, dfs(2, c / b, a, 0, 0);
    }
    if (n == 4) {
        ans[1] = {a, b, '+'};
        dfs(3, a + b, c, d, 0);
        ans[1] = {a, b, '-'};
        dfs(3, a - b, c, d, 0);
        ans[1] = {b, a, '-'};
        dfs(3, b - a, c, d, 0);
        ans[1] = {a, b, '*'};
        dfs(3, a * b, c, d, 0);
        if (b && a % b == 0)
            ans[1] = {a, b, '/'}, dfs(3, a / b, c, d, 0);
        if (a && b % a == 0)
            ans[1] = {b, a, '/'}, dfs(3, b / a, c, d, 0);

        ans[1] = {a, c, '+'};
        dfs(3, a + c, b, d, 0);
        ans[1] = {a, c, '-'};
        dfs(3, a - c, b, d, 0);
        ans[1] = {c, a, '-'};
        dfs(3, c - a, b, d, 0);
        ans[1] = {a, c, '*'};
        dfs(3, a * c, b, d, 0);
        if (c && a % c == 0)
            ans[1] = {a, c, '/'}, dfs(3, a / c, b, d, 0);
        if (a && c % a == 0)
            ans[1] = {c, a, '/'}, dfs(3, c / a, b, d, 0);
        ans[1] = {a, d, '+'};
        dfs(3, a + d, b, c, 0);
        ans[1] = {a, d, '-'};
        dfs(3, a - d, b, c, 0);
        ans[1] = {d, a, '-'};
        dfs(3, d - a, b, c, 0);
        ans[1] = {a, d, '*'};
        dfs(3, a * d, b, c, 0);
        if (d && a % d == 0)
            ans[1] = {a, d, '/'}, dfs(3, a / d, b, c, 0);
        if (a && d % a == 0)
            ans[1] = {d, a, '/'}, dfs(3, d / a, b, c, 0);
        ans[1] = {b, c, '+'};
        dfs(3, b + c, a, d, 0);
        ans[1] = {b, c, '-'};
        dfs(3, b - c, a, d, 0);
        ans[1] = {c, b, '-'};
        dfs(3, c - b, a, d, 0);
        ans[1] = {b, c, '*'};
        dfs(3, b * c, a, d, 0);
        if (c && b % c == 0)
            ans[1] = {b, c, '/'}, dfs(3, b / c, a, d, 0);
        if (b && c % b == 0)
            ans[1] = {c, b, '/'}, dfs(3, c / b, a, d, 0);
        ans[1] = {b, d, '+'};
        dfs(3, b + d, a, c, 0);
        ans[1] = {b, d, '-'};
        dfs(3, b - d, a, c, 0);
        ans[1] = {d, b, '-'};
        dfs(3, d - b, a, c, 0);
        ans[1] = {b, d, '*'};
        dfs(3, b * d, a, c, 0);
        if (d && b % d == 0)
            ans[1] = {b, d, '/'}, dfs(3, b / d, a, c, 0);
        if (b && d % b == 0)
            ans[1] = {d, b, '/'}, dfs(3, d / b, a, c, 0);
        ans[1] = {c, d, '+'};
        dfs(3, c + d, a, b, 0);
        ans[1] = {c, d, '-'};
        dfs(3, c - d, a, b, 0);
        ans[1] = {d, c, '-'};
        dfs(3, d - c, a, b, 0);
        ans[1] = {c, d, '*'};
        dfs(3, c * d, a, b, 0);
        if (d && c % d == 0)
            ans[1] = {c, d, '/'}, dfs(3, c / d, a, b, 0);
        if (c && d % c == 0)
            ans[1] = {d, c, '/'}, dfs(3, d / c, a, b, 0);
    }
    return;
}
int main() {
    cin >> a >> b >> c >> d;
    ans.resize(4);
    dfs(4, a, b, c, d);
    cout << "No answer!" << endl;
}
