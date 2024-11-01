#include<bits/stdc++.h>
using namespace std;
int vi[1010][1010],dx[7]={0,1,0,-1},dy[7]={1,0,-1,0}, n,m,k;
char a[1010][1010];
int ss(int x){
	if(x==3)return 0;
	else return x+1;
}
void dfs(int sx,int sy,int d,int s,int c){
	vi[sx][sy]=1;
	if(s>=k){
		cout<<c<<endl;
		return;
	}
	int x=sx+dx[d],y=sy+dy[d];
	if(x>n||x<1||y>m||y<1||a[x][y]=='x'){
		dfs(sx,sy,ss(d),s+1,c);
		return;
	}
	if(vi[x][y]==1)dfs(x,y,d,s+1,c);
	else dfs(x,y,d,s+1,c+1);
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int stx,sty,d;
		cin>>n>>m>>k>>stx>>sty>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vi[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(stx,sty,d,0,1);
	}
	return 0;
}
