#include<bits/stdc++.h>
using namespace std;
int n,m,k,xh,yh,d;
char a[1001][1001];
int v[1001][1001];
int ans=0;
void dfs(int x,int y,int step,int inf,int walk){
	if(step==0){ans=max(ans,walk);return ;}
	int nx,ny;
	if(inf==0){
		nx=x;ny=y+1;
	}
	if(inf==1){
		nx=x+1;ny=y;
	}
	if(inf==2){
		nx=x;ny=y-1;
	}
	if(inf==3){
		nx=x-1;ny=y;
	}
	if(v[nx][ny]==1){return ;}
	if(a[nx][ny]=='x'){
		v[nx][ny]=1;
		dfs(nx,ny,step-1,(inf+1)%4,walk);
		v[nx][ny]=0;
		return ;
	}
	v[nx][ny]=1;
	dfs(nx,ny,step-1,inf,walk+1);
	v[nx][ny]=0;
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,'0',sizeof(a));
		memset(v,0,sizeof(v));
		cin>>n>>m;
		cin>>xh>>yh>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(xh,yh,k,d,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
