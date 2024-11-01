#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,s[1005][1005],m,n,ans,yl[4]={1,0,-1,0},xl[4]={0,1,0,-1};
char maze[1005][1005];
void f(ll x,ll y,ll d,ll k){
	if(s[x][y]==0){
		s[x][y]=1;
		ans++;
	}
	if(!k){
		printf("%lld\n",ans);
		return;
	}
	if(maze[x+xl[d]][y+yl[d]]=='x'||x+xl[d]>n||y+yl[d]>m||x+xl[d]<1||y+yl[d]<1){
		f(x,y,(d+1)%4,k-1);
	}else{
		f(x+xl[d],y+yl[d],d,k-1);
	}
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		ll x,y,d,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		scanf("%lld%lld%lld",&x,&y,&d);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>maze[i][j];
				s[i][j]=0;
			}
		}
		f(x,y,d,k);
	}
	return 0;
}
