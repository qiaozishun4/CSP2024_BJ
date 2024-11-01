#include<bits/stdc++.h>
using namespace std;
bool chk(int x,int y,int n,int m){
	if(1<=x&&x<=n&&1<=y&&y<=m) return 1;
	return 0;
}
int d[5][5]={{0,1},{1,0},{0,-1},{-1,0}};
char a[1005][1005];
bool vis[1005][1005];
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,k,x,y,z,cnt=1;
		cin>>n>>m>>k;
		cin>>x>>y>>z;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			int xnow=x+d[z][0],ynow=y+d[z][1];
			if(a[xnow][ynow]!='x'&&chk(xnow,ynow,n,m)){
				x=xnow,y=ynow;
				if(vis[x][y]==0)cnt++;
				vis[x][y]=1;
			} else {
				z=(z+1)%4;
			}
		}
		cout<<cnt<<endl;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
