#include<bits/stdc++.h>
using namespace std;
long long n,m,k,T,x,y,d;
char c[1006][1006];
bool g[1006][1006];
void dfs(int x,int y,int d,long long cnt){
	if(k==0){
		cout<<cnt<<"\n";
		return ;
	}
	if(d==0){
		k-=1;
		if(x<1||x>n||y+1<1||y+1>m||c[x][y+1]=='x'){
			int d1=(d+1)%4;
			int cnt1=cnt;
			if(g[x][y]==0){
				cnt1+=1;
				g[x][y]=1;
			}
			dfs(x,y,d1,cnt1);
		}else{
			int cnt1=cnt;
			if(g[x][y+1]==0){
				cnt1+=1;
				g[x][y+1]=1;
			}
			dfs(x,y+1,d,cnt1);
		}
	}else if(d==1){
		k-=1;
		if(x+1<1||x+1>n||y<1||y>m||c[x+1][y]=='x'){
			int d1=(d+1)%4;
			int cnt1=cnt;
			if(g[x][y]==0){
				cnt1+=1;
				g[x][y]=1;
			}
			dfs(x,y,d1,cnt1);
		}else{
			int cnt1=cnt;
			if(g[x+1][y]==0){
				cnt1+=1;
				g[x+1][y]=1;
			}
			dfs(x+1,y,d,cnt1);
		}
	}else if(d==2){
		k-=1;
		if(x<1||x>n||y-1<1||y-1>m||c[x][y-1]=='x'){
			int d1=(d+1)%4;
			int cnt1=cnt;
			if(g[x][y]==0){
				cnt1+=1;
				g[x][y]=1;
			}
			dfs(x,y,d1,cnt1);
		}else{
			int cnt1=cnt;
			if(g[x][y-1]==0){
				cnt1+=1;
				g[x][y-1]=1;
			}
			dfs(x,y-1,d,cnt1);
		}
	}else{
		k-=1;
		if(x-1<1||x-1>n||y<1||y>m||c[x-1][y]=='x'){
			int d1=(d+1)%4;
			int cnt1=cnt;
			if(g[x][y]==0){
				cnt1+=1;
				g[x][y]=1;
			}
			dfs(x,y,d1,cnt1);
		}else{
			int cnt1=cnt;
			if(g[x-1][y]==0){
				cnt1+=1;
				g[x-1][y]=1;
			}
			dfs(x-1,y,d,cnt1);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
				g[i][j]=0;
			}
		}
		g[x][y]=1;
		dfs(x,y,d,1);
	}
	return 0;
}
