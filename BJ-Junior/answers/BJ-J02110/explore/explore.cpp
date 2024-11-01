#include<bits/stdc++.h>
using namespace std;
int ans=1,vis[1100][1100],n,m,f,k;
char a[1100][1100];
void dfs(int x,int y,int d,int cnt){
	if(cnt==k){
		f=1;
		return;
	}
	vis[x][y]=1;
	if(d==0&&a[x][y+1]=='.'&&f==0){
		if(vis[x][y+1]==0) ans++;
		dfs(x,y+1,d,cnt+1);
	}
	else if(d==1&&a[x+1][y]=='.'&&f==0){
		if(vis[x+1][y]==0) ans++;
		dfs(x+1,y,d,cnt+1);
	}
	else if(d==2&&a[x][y-1]=='.'&&f==0){
		if(vis[x][y-1]==0) ans++;
		dfs(x,y-1,d,cnt+1);
	}
	else if(d==3&&a[x-1][y]=='.'&&f==0){
		if(vis[x-1][y]==0) ans++;
		dfs(x-1,y,d,cnt+1);
	}
	else dfs(x,y,(d+1)%4,cnt+1);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int x,y,d;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		dfs(x,y,d,0);
		cout<<ans<<endl;
		memset(vis,0,sizeof(vis));
		ans=1;
		f=0;
	}
	return 0;
}