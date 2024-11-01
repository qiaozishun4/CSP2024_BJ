#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fx,fy,fd;
char mp[1005][1005];
bool h[1005][1005];
int ap[16];
void dfs(int x,int y,int c,int d){
	h[x][y]=1;
	if(c==k){
		return ;
	}
	int nx,ny;
	if(d==0){
		nx=x,ny=y+1;
	}
	if(d==1){
		nx=x+1,ny=y;
	}
	if(d==2){
		nx=x,ny=y-1;
	}
	if(d==3){
		nx=x-1,ny=y;
	}
	//cout<<nx<<" "<<ny<<" "<<d<<endl;
	if(nx<=n && ny<=m && nx>0 && ny>0 && mp[nx][ny]=='.'){
		dfs(nx,ny,c+1,d);
		//cout<<nx<<" "<<ny<<endl;
	}
	else{
		dfs(x,y,c+1,(d+1)%4);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				h[i][j]=0;
			}
		}
		cin>>fx>>fy>>fd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}	
		dfs(fx,fy,0,fd);
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(h[i][j]==1){
					cnt++;
				}
			}
		}
		ap[i]=cnt;
	}
	for(int i=1;i<=T;i++){
		cout<<ap[i]<<endl;
	}
	return 0;
}
