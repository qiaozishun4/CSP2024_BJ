#include<bits/stdc++.h>
using namespace std;

int T,n,m,k,s,e,d,ans;
char a[1005][1005]={};
bool vis[1005][1005]={};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>T;
	for(int g=1;g<=T;g++){
		memset(vis,false,sizeof(vis));
		ans=0;
		cin>>n>>m>>k>>s>>e>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vis[s][e]=1;
		int x=s,y=e,nx,ny;
		for(int i=1;i<=k;i++){
			if(d==0) {
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
			else{
				nx=x-1;
				ny=y;
			}
			if(nx<=0||nx>n||ny<=0||ny>m||a[nx][ny]=='x'){
				d=(d+1)%4;
			}
			else{
				x=nx;
				y=ny;
				vis[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
