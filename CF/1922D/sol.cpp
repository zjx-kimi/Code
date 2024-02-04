#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll N=300300;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')
          f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	  write(x/10);
	putchar(x%10+'0');
}
ll T,n,sum=0,ans=0;
ll a[N],d[N],l[N],r[N];
bool f[N];
set<ll> v,t;
void solve(){
	v.clear();
	n=read();
	sum=0;
	for(int i=1;i<=n;i++){
		f[i]=1;
		v.insert(i);
		a[i]=read();
		l[i]=i-1;
		r[i]=i+1;
	}
	for(int i=1;i<=n;i++)
	  d[i]=read();
	l[1]=r[n]=0;
	while(sum<n){
		sum++;
		for(auto i:v){
			if(a[l[i]]+a[r[i]]>d[i]){
				t.insert(i);
				f[i]=0;
			}
		}
		write(t.size());
		putchar(' ');
		v.clear();
		for(auto i:t){
			l[r[i]]=l[i];
			r[l[i]]=r[i];
			if(f[l[i]])
			  v.insert(l[i]);
			if(f[r[i]])
			  v.insert(r[i]);
		}
		t.clear();
	}
	putchar('\n');
}
int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	T=read();
	while(T--)
	  solve();
	return 0;
}
