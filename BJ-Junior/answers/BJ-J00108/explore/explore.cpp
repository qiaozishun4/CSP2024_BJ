#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int x,y,dir;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[1010][1010];
bool vis[1010][1010];
int cnt;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>dir;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=k;i++){
			vis[x][y]=true;
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			//cout<<i<<" "<<x<<" "<<y<<" "<<dir<<" "<<nx<<" "<<ny<<" "<<mp[nx][ny]<<endl;
			if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x'){
				dir=(dir+1)%4;
			}else{
				x=nx;
				y=ny;
			}
		}
		vis[x][y]=true;
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cnt+=vis[i][j];
			}
		}
		cout<<cnt<<endl;
	}
}