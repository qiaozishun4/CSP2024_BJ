#include<bits/stdc++.h>
using namespace std;
char t[2000][2000];
int n,m,x,y,d;
bool judge(int x,int y,int d){
	if(d==0){
		if(y+1<=m&&t[x][y+1]=='.'){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(d==1){
		if(x+1<=n&&t[x+1][y]=='.'){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(d==2){
		if(y-1>=1&&t[x][y-1]=='.'){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(d==3){
		if(x-1>=1&&t[x-1][y]=='.'){
			return 1;
		}
		else{
			return 0;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T){
		int k,ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		bool u[n+1][m+1]={};
		u[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>t[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(!judge(x,y,d)){
				d++;
				d=d%4;
				continue;
			}
			else{
				if(d==0){
					y++;
				}
				else if(d==1){
					x++;
				}
				else if(d==2){
					y--;
				}
				else{
					x--;
				}
				u[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(u[i][j]){
					ans++;
				}
			}	
		}
		cout<<ans<<endl;
		T--;
	}
	return 0;
}