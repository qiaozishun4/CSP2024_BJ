#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
char s[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,k,x,y,d,ans=1;
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		while(k--){
			int xx=x+dx[d],yy=y+dy[d];
			if(xx>=1 && xx<=n && yy>=1 && yy<=m && s[xx][yy]=='.'){
				x=xx;
				y=yy;
				if(!vis[x][y]) ans++;
				vis[x][y]=1;
			}
			else d=(d+1)%4;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=0;
	}
	return 0;
}