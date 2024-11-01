#include<bits/stdc++.h>
using namespace std;
char g[10010][10010]={};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		int n,m,k,x,y,d,ans=0;
		
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>g[i][j];
			}
		}
		g[x][y]='h';
		for(int i=0;i<k;i++){
			int xx,yy;

			switch(d){
				case 0:
				xx=x;
				yy=y+1;
				break;
				case 1:
				xx=x+1;
				yy=y;
				break;
				case 2:
				xx=x;
				yy=y-1;
				break;
				case 3:
				xx=x-1;
				yy=y;
				break;
				
			}
			if(xx>0&&xx<=n&&yy>0&&yy<=m&&g[xx][yy]!='x'){
				
				x=xx;y=yy;

				if(g[x][y]!='h'){
					ans++;
				g[x][y]='h';
			}
			}else{
	
			d=(d+1)%4;
		}
		}
		
		cout<<ans+1<<endl;
	
}
	
	return 0;
}
