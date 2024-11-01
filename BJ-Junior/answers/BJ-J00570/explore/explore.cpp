#include <bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int t,vis[N][N],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},a,b,k,l,h,r;
char g[N][N];
void dfs(int x,int y,int d,int cnt,int ans,int n,int m){
	if(cnt==0){
		cout<<ans<<endl;
		return;
	}
	int nx=x+dx[d],ny=y+dy[d];
	if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='x'){
		dfs(x,y,(d+1)%4,cnt-1,ans,n,m);
	}else{
		dfs(nx,ny,d,cnt-1,ans+1,n,m);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int f=1;f<=t;f++){
		memset(vis,0,sizeof(vis));
		cin>>a>>b>>k;
		cin>>l>>h>>r;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				cin>>g[a][b];
			}
		}
		dfs(l,h,r,k,1,a,b);
	}
	return 0;
}
