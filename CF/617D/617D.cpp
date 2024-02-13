/*
在平面直角坐标系上有三个点。我们的目标是画一个没有自交的简单折线，使得这条折线穿过三个点。同时，
折线的所有线段都只能与坐标轴平行。求出折线可能包含的最少的线段数。
*/
#include<bits/stdc++.h>
#define int long long
#define sz size()
#define pii pair <int, int>
using namespace std;
int X1, X2, X3, 
    Y1, Y2, Y3;
signed main(){
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
    if (X1 == X2 && X2 == X3) cout << 1;
    else if (Y1 == Y2 && Y2 == Y3) cout << 1;
    else if (X1 == X2 && !(Y1 < Y3 && Y3 < Y2 || Y2 < Y3 && Y3 < Y1)) cout << 2;
    else if (X2 == X3 && !(Y2 < Y1 && Y1 < Y3 || Y3 < Y1 && Y1 < Y2)) cout << 2;
    else if (X1 == X3 && !(Y1 < Y2 && Y2 < Y3 || Y3 < Y2 && Y2 < Y1)) cout << 2;
    else if (Y1 == Y2 && !(X1 < X3 && X3 < X2 || X2 < X3 && X3 < X1)) cout << 2;
    else if (Y1 == Y3 && !(X1 < X2 && X2 < X3 || X3 < X2 && X2 < X1)) cout << 2;
    else if (Y2 == Y3 && !(X2 < X1 && X1 < X3 || X3 < X1 && X1 < X2)) cout << 2;
    else cout << 3;
    return 0;
}