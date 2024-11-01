#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		ans=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		while(k--){
			int xx=x+dx[d],yy=y+dy[d];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[xx][yy]=='.'){
				x=xx;
				y=yy;
				ans++;
			}else{
				d=(d+1)%4;
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}