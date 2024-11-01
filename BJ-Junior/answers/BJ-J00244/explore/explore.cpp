#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,T,x,y,d,nx,ny,cnt;
bool mp[1010][1010],u[1010][1010];
char tmp;
int cx[4]={0,1,0,-1};
int cy[4]={1,0,-1,0};
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//3北 1南 2西 0东
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		cnt=1;
		memset(mp,0,sizeof(mp));
		memset(u,0,sizeof(u));
		u[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>tmp;
				if(tmp=='x') mp[i][j]=1;
			}
		}
		for(int i=1;i<=k;i++){
			nx=x+cx[d];
			ny=y+cy[d];
			//cout<<d<<' '<<x<<' '<<y<<' '<<nx<<' '<<ny<<endl;
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && !mp[nx][ny]){
				x=nx;
				y=ny;
				if(!u[x][y]) cnt++;
				u[x][y]=1;
			}else{
				d++;
				if(d==4) d=0;
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
