#include<bits/stdc++.h>
using namespace std;
struct kk{
	char l;
	int z;
}dfs[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long sum=1;
		int n,m,k,x,y,d;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>dfs[i][j].l;
				dfs[i][j].z=0;
			}
		}
		dfs[x][y].z=1;
		for(int i=1;i<=k;i++){
			int xd=x,yd=y;
			if(d==0)
				y++;
			else if(d==1)
				x++;
			else if(d==2)
				y--;
			else if(d==3)
				x--;
			if(!(x>=1&&x<=n&&y>=1&&y<=m)){
				x=xd;
				y=yd;
				d=(d+1)%4;
				continue;
			}if(dfs[x][y].l=='x'){
				x=xd;
				y=yd;
				d=(d+1)%4;
				continue;
			}
			if(dfs[x][y].z==0){
				sum++;
			}
			dfs[x][y].z=1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
