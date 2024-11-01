#include<bits/stdc++.h>
using namespace std;
const int N=1007;
char a[N][N];
bool vis[N][N];
int n,m,k;
void dfs(int x,int y,int d,int c){
	int cnt=c;
	while(1){
		if(k<=0){
			cout<<cnt<<'\n';
			return;
		}
		if(x+1>n||x-1<1||y+1>m||y-1<1) d=(d+1)%4,k--;
		else break;
		if(a[x][y+1]=='x'||a[x][y-1]=='x'||a[x+1][y]=='x'||a[x-1][y]=='x') d=(d+1)%4,k--;
		else break;
	}
	k--;
	if(d==0){
		int nx=x;
		int ny=y+1;
		if(vis[nx][ny]==0){
			vis[nx][ny]=1;
			dfs(nx,ny,d,cnt+1);
		}else{
			vis[nx][ny]=1;
			dfs(nx,ny,d,cnt);
		}
	}else if(d==1){
		int nx=x+1;
		int ny=y;
		if(vis[nx][ny]==0){
			vis[nx][ny]=1;
			dfs(nx,ny,d,cnt+1);
		}else{
			vis[nx][ny]=1;
			dfs(nx,ny,d,cnt);
		}
	}else if(d==2){
		int nx=x;
		int ny=y-1;
		if(vis[nx][ny]==0){
			vis[nx][ny]=1;
			dfs(nx,ny,d,cnt+1);
		}else{
			vis[nx][ny]=1;
			dfs(nx,ny,d,cnt);
		}
	}else{
		int nx=x-1;
		int ny=y;
		if(vis[nx][ny]==0){
			vis[nx][ny]=1;
			dfs(nx,ny,d,cnt+1);
		}else{
			vis[nx][ny]=1;
			dfs(nx,ny,d,cnt);
		}
	}
	
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.ans","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(x,y,d,1);
	}
	return 0;
}
