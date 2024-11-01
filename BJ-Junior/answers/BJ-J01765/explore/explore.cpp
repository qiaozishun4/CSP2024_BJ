#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
ll T;
ll n,m,k;
ll x,y,d;
char c;
bool maps[N][N];
bool vis[N][N];
ll ans=0,cnt=0;
void dfs(ll x,ll y,ll cnt){
	vis[x][y]=1;
	if(cnt>=k){
		ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(vis[i][j]) ans++;
			}
		}
		cout<<ans<<"\n";
		return ;
	}
	ll nx,ny;
	if(d==0){
		nx=x;
		ny=y+1;
	}
	else if(d==1){
		nx=x+1;
		ny=y;
	}
	else if(d==2){
		nx=x;
		ny=y-1;
	}
	else{
		nx=x-1;
		ny=y;
	}
	if(nx<1||nx>n||ny<1||ny>m){
		d=(d+1)%4;
		dfs(x,y,cnt+1);
		cnt++;		
	}
	else{
		if(maps[nx][ny]){
			dfs(nx,ny,cnt+1);
		}
		else{
			d=(d+1)%4;
			dfs(x,y,cnt+1);
			cnt++;		
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		memset(maps,0,sizeof(maps));
		ans=0;
		cnt=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>c;
				if(c=='.'){
					maps[i][j]=1;
				}
				else{
					maps[i][j]=0;
				}
			}
		}
		dfs(x,y,0);
	}
	return 0;
}
