#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

short visit[1005][1005];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(visit,0,sizeof(visit));
		int n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k>>x>>y>>d;
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char fff;
				fff=getchar();
				if(fff=='x')visit[i][j]=1;
				else visit[i][j]=0;
			}
			getchar();
		}
		x--;y--;
		visit[x][y]=2;
		ans=1;
		while(k--){
			if(d==0 && y+1<m && visit[x][y+1]!=1){
				y=y+1;
				if(visit[x][y]!=2){
					visit[x][y]=2;
					ans++;
				}
			}
			else if(d==1 && x+1<n && visit[x+1][y]!=1){
				x=x+1;
				if(visit[x][y]!=2){
					visit[x][y]=2;
					ans++;
				}
			}
			else if(d==2 && y-1>=0 && visit[x][y-1]!=1){
				y=y-1;
				if(visit[x][y]!=2){
					visit[x][y]=2;
					ans++;
				}
			}
			else if(d==3 && x-1>=0 && visit[x-1][y]!=1){
				x=x-1;
				if(visit[x][y]!=2){
					visit[x][y]=2;
					ans++;
				}
			}
			else d=(d+1)%4;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
				
