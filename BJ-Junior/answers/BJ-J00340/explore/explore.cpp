#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool vis[1010][1010];
int k;
int n,m;
int T;
int x,y,d;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int c=1;c<=T;c++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(a[x][y+1]=='.' && y+1<=m){
					y++;
					vis[x][y]=1;
				}
				else d=1;
			}
			else if(d==1){
				if(a[x+1][y]=='.' && x+1<=n){
					x++;
					vis[x][y]=1;
				}
				else d=2;
			}
			else if(d==2){
				if(a[x][y-1]=='.' && y-1>=1){
					y--;
					vis[x][y]=1;
				}
				else d=3;
			}
			else if(d==3){
				if(a[x-1][y]=='.' && x-1>=1){
					x--;
					vis[x][y]=1;
				}
				else d=0;
			}
			//cout<<x<<' '<<y<<endl;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]) sum++; 
			}
		}
		cout<<sum<<endl;
		memset(vis,false,sizeof(vis));
	}
	return 0;
}