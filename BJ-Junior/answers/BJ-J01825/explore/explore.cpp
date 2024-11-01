#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,v[1005][1005],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				v[i][j]=0;
			}
		}
		v[x][y]=1;
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>0&&ny>0&&nx<=n&&ny<=m&&c[nx][ny]=='.')x=nx,y=ny;
			else d=(d+1)%4;
			v[x][y]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=v[i][j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
