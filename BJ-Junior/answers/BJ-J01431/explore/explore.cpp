#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
ll n,m,k,sx,sy,sd,ans;
char c;
ll mapp[2005][2005],book[2005][2005];
ll walk[10][5]={{0,1},{1,0},{0,-1},{-1,0}};

void init(){
	for(ll i=0;i<=1500;i++){
		for(ll j=0;j<=1500;j++){
			mapp[i][j]=1e9;
			book[i][j]=0;
		}
	}
	ans=0;
}


void dfs(ll x,ll y,ll d,ll step){
	if(step>k) return;
	book[x][y]++;
	ll nx=x+walk[d][0],ny=y+walk[d][1];
	if(mapp[nx][ny]==0){
		dfs(nx,ny,d,step+1);
	}else{
		dfs(x,y,(d+1)%4,step+1);
	}
}


int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);	
	
	cin>>t;
	while(t--){
		init();

		scanf("%lld%lld%lld",&n,&m,&k);
		scanf("%lld%lld%lld",&sx,&sy,&sd);		
		
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
//				scanf("%c",&c);
				cin>>c;
				if(c=='.'){
					mapp[i][j]=0;
				}
			}
		}
		
		dfs(sx,sy,sd,0);
		
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(book[i][j]!=0){
					ans++;
				}
			}
		}
		
		cout<<ans<<endl;
		
	}	
	return 0;
}
