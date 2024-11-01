#include<iostream>
using namespace std;
const int N = 1e3+5;
int m,n,d,x1,y2,k,cnt=0,ans=1,vis[N][N];
char a[N][N];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void dfs(int x,int y){
	if(cnt >= k){
		return;
	}
	for(int i=1;i<=4;i++){
		cnt ++;
		int nx = x+dx[d];
		int ny = y+dy[d];
		if(nx >= 1 && nx <= n &&
		   ny >= 1 && ny <= m && 
		   a[nx][ny] == '.'){
			//cout<<nx<<" "<<ny<<"\n";
			if (vis[nx][ny] == 0) ans ++;
			vis[nx][ny] =  1;
			dfs(nx,ny);			
			break;
		}else d = (d+1)%4;
		if(cnt >= k) return;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","W",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x1>>y2>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(x1,y2);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
 
*/
	
