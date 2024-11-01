#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,xx,yy,dd,tx,ty,step;
long long ans;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
string s;
char mmap[10000][10000];
bool vis[10000][10000];
void solve(int x,int y,int d,long long cnt){
    for(step=0;step<=k;step++){
		cnt+=!vis[x][y];
		vis[x][y]=1;
		tx=x+dir[d][0];ty=y+dir[d][1];
		if(tx<1||tx>n||ty<1||ty>m||mmap[tx][ty]=='x')
			d=(d+1)%4;
		else
			x=tx,y=ty;
   }
   ans=cnt;
}
int  main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>xx>>yy>>dd;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++){
				mmap[i][j]=s[j-1];
			}
		}
		solve(xx,yy,dd,0);
		cout<<ans<<endl;
	}
	return 0;
}
