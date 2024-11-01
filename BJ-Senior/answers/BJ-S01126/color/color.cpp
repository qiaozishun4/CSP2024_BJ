// 会赢吗？
//14:45 hui C, kai xie
//15:06 finish
//记得对排！！！
#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b,c)    for(int i=(a),i##end=(b);i<=(i##end);i+=(c))
#define per(i,a,b,c)    for(int i=(a),i##end=(b);i>=(i##end);i-=(c))
#define pb push_back
#define pii pair<int,int>
#define vint vector<int>
using namespace std;

const int maxn=2.2e5;

int a[maxn];
int f[1020000];

void solve(){
	int n,mv=0;cin>>n;
	rep(i,1,n,1)    cin>>a[i],mv=max(mv,a[i]);
	memset(f,~0x3f,sizeof(f));
	f[0]=0;
	int ta=0,ma=0;

	rep(i,1,n,1){
		ta+=(a[i]==a[i-1]?a[i]:0);        
		f[a[i-1]]=max({f[a[i-1]],ma-ta,f[a[i]]+a[i]-(a[i]==a[i-1]?a[i]:0)});
		ma+=(a[i]==a[i-1]?a[i]:0);
		ma=max(ma,f[a[i-1]]+ta);
	}   
	cout<<ma<<endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;
	while(T--)  solve();
	return 0;
}