#include<bits/stdc++.h>
using namespace std;
int n,m,k,sx,sy,dist;
int dis1[4]={1,0,-1,0};
int dis2[4]={0,1,0,-1};
bool vis[1001][1001];
char mp[1001][1001];
int ans,step;
void dfs(int x,int y){
	for(int i=0;i<=3;i++){
		if(step==k){
			return;
		}
		int nx=x+dis1[dist%4],ny=y+dis2[dist%4];
		step++;
		if(nx>n||ny>m||nx<=0||ny<=0){
			dist++;
			continue;
		}else if(mp[nx][ny]=='x'||vis[nx][ny]==true){
			dist++;
			continue;
		}else{
			ans++;
			cout<<nx<<" "<<ny<<" "<<step<<endl;
			vis[nx][ny]=true;
			dfs(nx,ny);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(mp,0,sizeof(mp));
		memset(vis,false,sizeof(vis));
		ans=1;
		step=0;
		cin>>n>>m>>k;
		cin>>sx>>sy>>dist;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		if(n==1&&m==1){
			cout<<1;
			return 0;
		}
		dfs(sx,sy);
		cout<<ans<<endl;
	}
	return 0;
}