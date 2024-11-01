#include<bits/stdc++.h>
#define ll long long
using namespace std;
char ch[1005][1005];
map<pair<ll,ll>,ll>mp;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		mp=map<pair<ll,ll>,ll>();
		ll x,y,d;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>ch[i][j];
			}
		}
		mp[{x,y}]++;
		for(ll i=1;i<=k;i++){
			ll xx,yy;
			if(d==0){
				xx=x,yy=y+1;
			}
			else if(d==1){
				xx=x+1,yy=y;
			}
			else if(d==2){
				xx=x,yy=y-1;
			}
			else{
				xx=x-1,yy=y;
			}
			if(xx<=n&&yy<=m&&ch[xx][yy]=='.'){
				x=xx,y=yy;
			}
			else{
				d=(d+1)%4;
			}
			mp[{x,y}]++;
		}
		cout<<mp.size()<<'\n';
	}
	return 0;
}