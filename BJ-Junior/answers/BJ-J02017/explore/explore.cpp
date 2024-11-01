#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
typedef long long ll;
ll n,m,k;
ll x,y,d;
char a[N][N];
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
bool v[N][N];
void solve(){
	memset(v,0,sizeof v);
	ll ans=0;
	ll cx=x,cy=y;
	v[x][y]=true;
	while(k>0){
		ll nx=cx+dx[d],ny=cy+dy[d];
		if(nx<1 || nx>n || ny<1 || ny>m || a[nx][ny]=='x'){
			d=(d+1)%4,k--;
		}
		else{
			k--;
			cx=nx,cy=ny;
			v[nx][ny]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[i][j]){
				 ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++) cin>>a[i][j];
		}
		solve();
	}
	return 0;
}
