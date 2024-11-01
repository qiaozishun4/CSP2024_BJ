#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
char s[1005][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll t,n,m,k,x,y,d,i,j,ans;
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		ans=0;
		while(k--){
			ll xx=x+dx[d];
			ll yy=y+dy[d];
			if(xx>n||yy>m) break;
			while(q<=5&&s[xx][yy]=='x'){
				d=(d+1)%4;
				q++;
			}
			if(q==5) break;
			xx=x+dx[d];
			yy=y+dy[d];
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}