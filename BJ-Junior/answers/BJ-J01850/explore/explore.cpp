#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;
int nx,ny;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
char mp[N][N];
bool vis[N][N];
int T,n,m,k,x,y,d;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		//快乐打磨你启动
		while(k--){
			nx=x+dx[d];
			ny=y+dy[d];
			while((nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x')&&k){
				d=(d+1)%4;
				nx=x+dx[d];
				ny=y+dy[d];
				k--;
			}
			if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x')continue;
			x=nx;
			y=ny;
			vis[nx][ny]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=vis[i][j];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
