#include<bits/stdc++.h>
using namespace std;
char a[1001][1001]={};
int n,m,k,t,ans1,ans;
bool vis[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int d){
	if(ans>=k){
		return ;	
	}
	for(int i=d;i<d+4;i++){
		if(ans>=k){
			return ;
		}
		if(d!=i){
			ans++;
		}
		int tx=x+dx[i%4];
		int ty=y+dy[i%4];
		if(tx>0&&tx<=n&&ty>0&&ty<=m&&a[tx][ty]=='.'){
			ans++;
			ans1++;
			a[tx][ty]='x';
			dfs(tx,ty,i%4);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		ans=0;
		ans1=0;
		int f,z,D;
		cin>>f>>z>>D;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				vis[i][j]=0;
			}
		}
		dfs(f,z,D);
		cout<<ans1<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}