#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
vector <N> Edge[N];

void dfs(int x, int fa){
	cout << x << " ";
	for (int v : Edge[x]) {
		int v = g[x][i];
		if (v != fa) dfs(v, x);
	}
}

int main(){
	cin >> n;
	for (int i = 1, u, v; i <= n; i++){
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
        if (Edge[i].size() == 1) 
            dfs(i, -1);
    
	return 0;
}
