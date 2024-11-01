#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll n,m;
ll k;
ll x,y,d;
string s;
char a[1010][1010];
ll cnt;
bool flag[1010][1010];
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++){
			cin>>s;
			for(ll j=1;j<=m;j++){
				flag[i][j]=false;
				a[i][j]=s[j-1];
			}
		}
		cnt=1;
		flag[x][y]=true;
		for(ll i=1;i<=k;i++){
			ll xp,yp;
			if(d==0){
				xp=x,yp=y+1;
			}
			if(d==1){
				xp=x+1,yp=y;
			}
			if(d==2){
				xp=x,yp=y-1;
			}
			if(d==3){
				xp=x-1,yp=y;
			}
			if(xp>0&&yp>0&&xp<=n&&yp<=m&&a[xp][yp]=='.'){
				x=xp,y=yp;
				flag[x][y]=true;
			}else{
				d=(d+1)%4;
			}
		}
		cnt=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(flag[i][j])
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
