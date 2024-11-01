#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int t,n,m,k,x,y,d,vis[N][N];
char c[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int tx,ty;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		vis[x][y]=1;
		while(k--){
			if(d==0){
				tx=x;
				ty=y+1;
			}   
			else if(d==1){
				tx=x+1;
				ty=y;
			}  
			else if(d==2){
				tx=x;
				ty=y-1;
			}    
			else{
				tx=x-1;
				ty=y;
			} 
			if(tx>n||tx<1||ty>m||ty<1||c[tx][ty]=='x')d=(d+1)%4;
			else if(tx<=n&&tx>=1&&ty<=m&&ty>=1&&c[tx][ty]=='.'){
				x=tx;
				y=ty;
				vis[x][y]=1; 
			}                                                        
		}
		int ans=0;                                              
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1)ans++;
			}
		} 
		cout<<ans<<"\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	}
	return 0;
}