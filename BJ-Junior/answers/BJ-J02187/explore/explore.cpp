#include<bits/stdc++.h>
using namespace std;
const int N=1003;
int T,n,m,k,sx,sy,d;
char a[N][N];
bool vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int ans=1;
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k>>sx>>sy>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vis[sx][sy]=1;
		for(int i=1;i<=k;i++){
			int nx=0,ny=0;
			if(!d) nx=sx,ny=sy+1;
			if(d==1) nx=sx+1,ny=sy;
			if(d==2) nx=sx,ny=sy-1;
			if(d==3) nx=sx-1,ny=sy;
			if(a[nx][ny]=='.'&&1<=nx&&nx<=n&&1<=ny&&ny<=m){
				sx=nx,sy=ny;
				if(!vis[nx][ny]) vis[nx][ny]=1,ans++;
			}else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}