#include<bits/stdc++.h>
using namespace std;
char mp[1000+10][1000+10];
bool b[1000+10][1000+10];
bool vis[1000+10][1000+10];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int n,m,k;
int x,y,d;
int ma;
void dfs(int x,int y,int step){
	if(step==k){
		return ;
	}
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(nx<0||nx>=n||ny<0||ny>=m)continue;
		if(vis[nx][ny]==1||mp[nx][ny]=='x')continue;
		vis[nx][ny]=1;
		b[nx][ny]=1;
		dfs(nx,ny,step+1);
		vis[nx][ny]=0;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>mp[i][j];
			}
		}
		int cnt=0;
		x--;
		y--;
		if(d==0)y++;
		else if(d==1)x++;
		else if(d==2)y--;
		else x--;
		dfs(x,y,1);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(b[i][j]==1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
