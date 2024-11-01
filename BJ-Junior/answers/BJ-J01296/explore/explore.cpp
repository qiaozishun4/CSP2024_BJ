#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dx[5]={0,1,0,-1};
ll dy[5]={1,0,-1,0},n,m,d,k;
char a[1005][1005];
bool v[1005][1005];
void dfs(ll x,ll y,ll d,ll z){
	v[x][y]=1;
	if(z>k){
		return;
	}
	ll xx=x+dx[d];
	ll yy=y+dy[d];
	if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
		dfs(xx,yy,d,z+1);
	}
	else{
		dfs(x,y,(d+1)%4,z+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		ll x,y,i,j;
		cin>>n>>m>>k>>x>>y>>d;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(x,y,d,1);
		ll ans=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(v[i][j]==1){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}