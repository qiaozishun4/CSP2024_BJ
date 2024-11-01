#include<bits/stdc++.h>
using namespace std;
int T,dt[1020][1020],zg[1020][1020],n,m,k,x,y,d,xp,yp,ans[10];
char s[1020];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int rt=1;rt<=T;rt++){
		memset(dt,0,sizeof(dt));
		memset(zg,0,sizeof(zg));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		zg[x][y]=1;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=0;j<m;j++) if(s[j]=='.') dt[i][j+1]=1;
		}
		for(int i=1;i<=k;i++){
			if(d==0) xp=x,yp=y+1;
			else if(d==1) xp=x+1,yp=y;
			else if(d==2) xp=x,yp=y-1;
			else xp=x-1,yp=y;
			if(dt[xp][yp]==1){
				x=xp,y=yp;
				xp=0,yp=0;
				zg[x][y]=1;
				//cout<<x<<" "<<y<<endl;
			}
			else d=(d+1)%4;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(zg[i][j]==1) ans[rt]++;
	}
	for(int i=1;i<=T;i++){
		
		cout<<ans[i]<<endl;
	}
	return 0;
}