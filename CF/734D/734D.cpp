#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 * 5 + 5;
struct node {
    char chess;
    int x, y;
} a[MAXN];
int n, x, y, up, dw, le, ri, lu, ld, ru, rd;
bool flag;
int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].chess >> a[i].x >> a[i].y;
        if (a[i].x == x) {
            if (a[i].y > y && up == 0 || a[i].y < a[up].y)
                up = i;
            else if (a[i].y < y && dw == 0 || a[i].y > a[dw].y)
                dw = i;
        }
        if (a[i].y == y) {
            if (a[i].x > x && ri == 0 || a[i].x < a[ri].x)
                ri = i;
            else if (a[i].x < x && le == 0 || a[i].x > a[le].x)
                le = i;
        }
        if (a[i].x - x == a[i].y - y) {
            if (a[i].x > x && ru == 0 || a[i].x < a[ru].x)
                ru = i;
            else if (a[i].x < x && ld == 0 || a[i].x > a[ld].x)
                ld = i;
        }
        if (a[i].x - x == y - a[i].y) {
            if (a[i].x > x && rd == 0 || a[i].x < a[rd].x)
                rd = i;
            else if (a[i].x < x && lu == 0 || a[i].x > a[lu].x)
                lu = i;
        }
    }
    if (a[up].chess == 'R' || a[up].chess == 'Q') flag = 1;
    if (a[dw].chess == 'R' || a[dw].chess == 'Q') flag = 1;
    if (a[le].chess == 'R' || a[le].chess == 'Q') flag = 1;
    if (a[ri].chess == 'R' || a[ri].chess == 'Q') flag = 1;
    if (a[lu].chess == 'B' || a[lu].chess == 'Q') flag = 1;
    if (a[ru].chess == 'B' || a[ru].chess == 'Q') flag = 1;
    if (a[ld].chess == 'B' || a[ld].chess == 'Q') flag = 1;
    if (a[rd].chess == 'B' || a[rd].chess == 'Q') flag = 1;
    if (flag == true)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
