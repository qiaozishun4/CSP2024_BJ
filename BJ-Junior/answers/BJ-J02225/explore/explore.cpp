#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e3+5;
char m1[MAXN][MAXN],m2[MAXN][MAXN];
ll T,n,m,k,x,y,d,ans,nx,ny;
const ll dir[][2]={{0,1},{1,0},{0,-1},{-1,0}};
void go(){
	nx=x+dir[d][0];
	ny=y+dir[d][1];
	if(m1[nx][ny]=='.'){
		x=nx;
		y=ny;
		m2[nx][ny]='x';
	}else{
		d=(d+1)%4;
	}
}
void check(){
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=m;++j){
			ans+=(m1[i][j]==m2[i][j]?0:1);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		fill(m1[0],m1[MAXN],'x');
		fill(m2[0],m2[MAXN],'x');
		ans=0;
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=m;++j){
				cin>>m1[i][j];
				m2[i][j]=m1[i][j];
			}
		}
		m2[x][y]='x';
		while(k--){
			go();
		}
		check();
		cout<<ans<<endl;
	}
	return 0;
}
