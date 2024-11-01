#include <bits/stdc++.h>
using namespace std;
int n,m,k,q,a[1001][1001],x,y,p,X[4]={0,1,0,-1},Y[4]={1,0,-1,0},ans;
bool book[1001][1001];
char c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>q;
	while(q--){
		ans=1;
		cin>>n>>m>>k>>x>>y>>p;
		memset(book,0,sizeof(book));
		book[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c=='.'){
					a[i][j]=0;
				}
				else{
					a[i][j]=1;
				}
			}
		}
		while(k--){
			int nx=x+X[p],ny=y+Y[p];
			if(nx>n||nx<=0||ny>m||ny<=0||a[nx][ny]==1){
				p++;
				if(p==4) p=0;
				continue;
			}
			x=nx;
			y=ny;
			if(!book[x][y]){
				book[x][y]=1;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
