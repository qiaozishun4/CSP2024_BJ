#include<bits/stdc++.h>
using namespace std;
int t,n,m;
char ma[1005][1005];
bool vis[1005][1005];
void dfs(int x,int y,int d,int k){
	if(k==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1) sum++;
			}
		}
		cout<<sum<<endl;
		return;
	}
	int xx,yy;
	if(d==0){
		xx=x;
		yy=y+1;
		}
	if(d==1){
		xx=x+1;
		yy=y;
	}
	if(d==2){
		xx=x;
		yy=y-1;
	}
	if(d==3){
		xx=x-1;
		yy=y;
	}
	if(ma[xx][yy]=='.' && (xx>0 && xx<=n) && (y>0 && y<=m)){
		vis[xx][yy]=1;
		dfs(xx,yy,d,k-1);
		vis[xx][yy]=0;
	}
	else{
		dfs(x,y,(d+1)%4,k-1);
	}
	
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
		int k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ma[i][j];
			}
		}
		dfs(x,y,d,k);
		vis[x][y]=0;
	}
    return 0;
}
