#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,k,x0,y0,d0,count=1;
		cin>>n>>m>>k>>x0>>y0>>d0;
		char explore[n][m];
		int x=x0-1,y=y0-1,d=d0;
		int vis[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>explore[i][j];
				vis[i][j]=1;
			}
		}
		vis[x][y]=0;
		for(int i=0;i<k;i++){
			if(d==0){
				if(y+1<m&&explore[x][y+1]!='x'){
					y+=1;
					if(vis[x][y]==1){
						vis[x][y]=0;
						count++;
					}
				}
				else{
					d+=1;
					d%=4;
				}
			}
			else if(d==1){
				if(x+1<n&&explore[x+1][y]!='x'){
					x+=1;
					if(vis[x][y]==1){
						vis[x][y]=0;
						count++;
					}
				}
				else{
					d+=1;
					d%=4;
				}
			}
			else if(d==2){
				if(y-1>=0&&explore[x][y-1]!='x'){
					y-=1;
					if(vis[x][y]==1){
						vis[x][y]=0;
						count++;
					}
				}
				else{
					d+=1;
					d%=4;
				}
			}
			else if(d==3){
				if(x-1>=0&&explore[x-1][y]!='x'){
					x-=1;
					if(vis[x][y]==1){
						vis[x][y]=0;
						count++;
					}
				}
				else{
					d+=1;
					d%=4;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
