#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
char h[1003][1003];
bool can[1003][1003];
void dfs(int x,int y,int k,int d){
	if(k==0)return ;
	int nx=x+dx[d],ny=y+dy[d];
	if((nx<1||nx>n||ny<1||ny>m)||h[nx][ny]=='x'){
		dfs(x,y,k-1,(d+1)%4);
	}else{
		can[nx][ny]=true;
		dfs(nx,ny,k-1,d);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long an=0;
		cin>>n>>m>>k>>x>>y>>d;
		memset(can,false,sizeof(can));
		can[x][y]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)cin>>h[i][j];
		}
		dfs(x,y,k,d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(can[i][j])an++;
			}
		}
		cout<<an<<'\n';
	}
	return 0;
}
