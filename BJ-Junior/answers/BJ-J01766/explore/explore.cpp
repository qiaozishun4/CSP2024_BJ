#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,d,sx,sy,ans=1;
int mp[1010][1010];
bool flag[1010][1010];
int dir[4][2]={
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		memset(mp,0,sizeof(mp));
		memset(flag,0,sizeof(flag));
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				if(c=='x')mp[i][j]=1;
			}
		}
		int x=sx,y=sy;
		while(k){
			int nx=x+dir[d][0];
			int ny=y+dir[d][1];
			flag[x][y]=1;
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&!mp[nx][ny]){
				if(!flag[nx][ny])ans++;
				x=nx;
				y=ny;
				k--;
			}
			else {
				d=((d+1)%4);
				k--;
			}
		}
		cout<<ans<<endl;
		ans=1;
	}
}
