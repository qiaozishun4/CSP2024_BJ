#include<bits/stdc++.h>
using namespace std;
int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int u;
    cin>>u;
    for(int uu=0; uu<u; uu++){
		int n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k>>x>>y>>d;
		x--;
		y--;
		bool a[1000][1000],b[1000][1000];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				char c;
				scanf(" %c",&c);
				if(c=='.'){
					a[i][j]=1;
				}
				else{
					a[i][j]=0;
				}
				b[i][j]=0;
			}
		}
		b[x][y]=1;
		for(int i=0; i<k; i++){
			int tx=x+xx[d%4],ty=y+yy[d%4];
			if(tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]==1){
				x=tx;
				y=ty;
				if(b[x][y]==0){
					ans++;
				}
				b[x][y]=1;
			}
			else{
				d++;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
