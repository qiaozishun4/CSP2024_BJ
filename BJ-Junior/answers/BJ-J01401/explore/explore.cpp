#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k;
int xx0,yy0,dd0;
char g[N][N];
int dis[4][2]={0,1,1,0,0,-1,-1,0};
bool vis[N][N];
void solve(){
	memset(vis,0,sizeof(vis));
	cin>>n>>m>>k>>xx0>>yy0>>dd0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}
	int x=xx0,y=yy0,d=dd0;
	int xx1,yy1;
	int sum=1;
	vis[x][y]=1;
	for(int i=1;i<=k;i++){
		xx1=dis[d][0]+x;
		yy1=dis[d][1]+y;
		if(1<=xx1&&xx1<=n&&1<=yy1&&yy1<=m&&g[xx1][yy1]=='.'){
			if(vis[xx1][yy1]==0){
				vis[xx1][yy1]=1;
				//~ cout<<xx1<<" "<<yy1<<endl;
				sum++;
			}
			x=xx1;
			y=yy1;
		}
		else{
			d=(d+1)%4;
			//~ cout<<"right-->"<<d<<endl;
		}
	}
	cout<<sum<<endl;
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
1 5 4
1 1 2
....x
 */
