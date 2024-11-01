#include<bits/stdc++.h>
using namespace std;
int xx[5]={0,1,0,-1};
int xy[5]={1,0,-1,0};
char c[1005][1005];
bool vis[1005][1005];
int x,y,n,m,k,d,ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
				vis[i][j]=0;
			}
		for(int i=1;i<=k;i++){
			int nx=x+xx[d],ny=y+xy[d];
			//
			if(c[nx][ny]=='x' || nx>n || ny>m ||nx<=0||ny<=0){
				d=(d+1)%4;
				continue;
			}
			else{
				//vis[x][y]=0;
				x=nx;
				y=ny;
				if(vis[x][y]==0){
					vis[x][y]=1;
					ans++;
					//cout<<nx<<' '<<ny<<endl;
				}
				
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
