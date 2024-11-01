#include <bits/stdc++.h>
using namespace std;
char mp[1005][1005];
bool v[1005][1005];
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		memset(v,1,sizeof v);
		int n,m,k,x,y,d;
		bool f=0;
		cin>>n>>m>>k>>x>>y>>d;
		if(n<100&&m<100&&k==1) f=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				if(mp[i][j]=='.') v[i][j]=0;
			}
		}
		v[x][y]=1;
		int dx,dy,c=1;
		if(f){//40pts
			int tdx=x+dir[d][0],tdy=y+dir[d][1];
			if(tdx<1||tdy<1||tdx>n||tdy>m||mp[tdx][tdy]=='x'){
				cout<<1<<endl;
				continue;
			}
			else{
				cout<<2<<endl;
				continue;
			}
		}else{
			while(k--){
				dx=x+dir[d][0];
				dy=y+dir[d][1];
				while(dx<1||dy<1||dx>n||dy>m||mp[dx][dy]=='x'){
					dx=x;
					dy=y;
					d=(d+1)%4;
					--k;
					dx=x+dir[d][0];
					dy=y+dir[d][1];
				}
				if(!v[dx][dy]) c++;
				v[dx][dy]=1;
				x=dx,y=dy;
			}
	    }
		cout<<c<<endl;	
	}
	return 0;
}
