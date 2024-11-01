#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5;
ll n;
ll T;
ll a[N+5];
ll res;
ll color[N+5];

void dfs(ll x,ll ans){
	if(x==n+1){
		res=max(ans,res);
		return ;
	}
	color[x]=0;
	ll i;
	for(i=x-1;i>=1;i--)
		if(color[x]==color[i])
			break;
	if(a[i]==a[x])
		dfs(x+1,ans+a[x]);
	else
		dfs(x+1,ans);
	color[x]=1;
	for(i=x-1;i>=1;i--)
		if(color[x]==color[i])
			break;
	if(a[i]==a[x])
		dfs(x+1,ans+a[x]);
	else
		dfs(x+1,ans);
	return ;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		a[0]=-1;
		res=0;
		dfs(1,0);
		cout<<res<<"\n";
	}
	return 0;
}
//caijiuduolian