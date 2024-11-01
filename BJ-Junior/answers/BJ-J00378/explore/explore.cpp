#include<iostream>
using namespace std;
const int N = 1e3+7;
char a[N][N];
int vis[N][N];
int n,m,k;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y,int d,int step){
	if(step > k) return;
	vis[x][y] = 1;
	int xx = x+dx[d];
	int yy = y+dy[d];
	if(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy] != 'x') dfs(xx,yy,d,step+1);
	else{
		while(xx==0 || xx>n || yy==0 || yy>m || a[xx][yy] == 'x'){
			if(step > k) return;
			d = (d+1)%4;
			step++;
			xx = x+dx[d];
			yy = y+dy[d];
		}
		dfs(xx,yy,d,step+1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				vis[i][j] = 0;
			}
		dfs(x,y,d,0);
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j] == 1)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
