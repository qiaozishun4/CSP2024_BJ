#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1005][1005],vis[1005][1005],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool check(int x,int y){
	if(x>n||x<1||y>m||y<1||a[x][y])	return 0;
	return 1;
}
void dfsc(int x,int y,int d,int times){
	vis[x][y]=1;
	if(times==k)	return ;
	int nx=x+dx[d];
	int ny=y+dy[d];
	if(check(nx,ny)){
		dfsc(nx,ny,d,times+1);
	}else{
		dfsc(x,y,(d+1)%4,times+1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char l;
				cin>>l;
				if(l=='x'){
					a[i][j]=1;
				}else{
					a[i][j]=0;
				}
				vis[i][j]=0;
			}
		}
		dfsc(x,y,d,0);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
