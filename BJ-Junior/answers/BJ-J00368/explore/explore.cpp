#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int T;
int n,m,k;
char g[N][N];
bool vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	int x,y,d;
	int nx,ny;
	int ans;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>g[i][j];
			}
		}
		ans=1;
		memset(vis,0,sizeof(vis));
		vis[x][y]=true;
		//若 d = 0,则令 (x ′ , y ′ ) = (x, y + 1),
		//若 d = 1,则令(x ′ , y ′ ) = (x + 1, y),
		//若d = 2,则令 (x ′ , y ′ ) = (x, y − 1),
		//若 d = 3,则令(x ′ , y ′ ) = (x − 1, y)。
		for(int i=1;i<=k;i++){
			if(d==0){
				nx=x;
				ny=y+1;
			}
			else if(d==1){
				nx=x+1;
				ny=y;
			}
			else if(d==2){
				nx=x;
				ny=y-1;
			}
			else if(d==3){
				nx=x-1;
				ny=y;
			}
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&g[nx][ny]!='x'){
				if(vis[nx][ny]==false){
					ans++;
					vis[nx][ny]=true;
				}
				x=nx,y=ny;
				//printf("move from %d,%d to %d,%d   ans=%d\n",x,y,nx,ny,ans);
			}
			else{
				d=(d+1)%4;
				//printf("turn to %d   cause %d,%d\n",d,nx,ny);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}