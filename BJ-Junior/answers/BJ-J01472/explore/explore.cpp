#include<bits/stdc++.h>
using namespace std;
int n,m,t,d,k,stx,sty,vis[1000+10][1000+10];
char a[1000+10][1000+10];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void solve(int stx,int sty,int fang,int k){
	int x=stx,y=sty,d=fang,cnt=k;
	vis[x][y]=1;
	while(cnt--){
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x'){
			d=(d+1)%4;
		}else{
			x=nx;
			y=ny;
			vis[x][y]=1;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>stx>>sty>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				vis[i][j]=0;
			}
		}
		solve(stx,sty,d,k);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
