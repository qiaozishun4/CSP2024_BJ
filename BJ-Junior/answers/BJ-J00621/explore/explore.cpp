#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,sx,sy,sd,ans;
char a[1003][1003];
bool vis[1003][1003][5];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct node{
	ll x,y,d,cnt;
};
void bfs(){
	queue<node> q;
	vis[sx][sy][sd]=1;
	q.push({sx,sy,sd,0});
	while(q.size()){
		node u=q.front();q.pop();
		ll nx=u.x+dx[u.d],ny=u.y+dy[u.d];
		if(u.cnt+1>k) continue;
		if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x'){
			if(!vis[u.x][u.y][(u.d+1)%4]){
				q.push({u.x,u.y,(u.d+1)%4,u.cnt+1});
				vis[u.x][u.y][(u.d+1)%4]=1;
			}
		}else if(!vis[nx][ny][u.d]){
			vis[nx][ny][u.d]=1;
			q.push({nx,ny,u.d,u.cnt+1});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			ans+=max({vis[i][j][0],vis[i][j][1],vis[i][j][2],vis[i][j][3]});
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(),cout.tie();
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>sx>>sy>>sd;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>a[i][j];vis[i][j][0]=vis[i][j][1]=vis[i][j][2]=vis[i][j][3]=0;
			}
		}
		ans=0;bfs();
		cout<<ans<<"\n";
	}
	return 0;//zpyzpy
}
