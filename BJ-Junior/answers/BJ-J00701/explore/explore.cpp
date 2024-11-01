#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char mp[1005][1005];
bool vis[1005][1005];
void fun(){
	memset(vis,0,sizeof(vis));
	int n,m,k,x,y,d;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++){
		cin>>(mp[i]+1);
	}
	vis[x][y]=true;
	while(k--){
		int tx=x+dx[d],ty=y+dy[d];
		if(mp[tx][ty]=='x'||tx<1||tx>n||ty<1||ty>m){
			d++;
			d%=4;
			tx=x+dx[d];
			ty=y+dy[d];
			continue;
		}
		x=tx;
		y=ty;
		vis[x][y]=true;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans+=vis[i][j];
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		fun();
	}
	return 0;
}
