#include<bits/stdc++.h>
using namespace std;
char mp[1050][1050];int vis[1050][1050];
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t,n,m,k,rx,ry,d;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		int cnt=1;
		cin>>n>>m>>k;
		cin>>rx>>ry>>d;
		vis[rx][ry]=1;
		for(int i=1; i<=n;i++){
			for(int j=1; j<=m; j++){
				cin>>mp[i][j];
			}
		}
		for(int i=0;i<k;i++){
			int tx=rx,ty=ry;
			if(d==0){
				ty+=1;
			}else if(d==1){
				tx+=1;
			}else if(d==2){
				ty-=1;
			}else if(d==3){
				tx-=1;
			}
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&mp[tx][ty]=='.'){
				rx=tx;
				ry=ty;
				if(vis[rx][ry]==0){
					cnt++;
					vis[rx][ry]=1;
				}
			}else{
				d = (d+1)%4;
			}
		}
		cout<<cnt<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

