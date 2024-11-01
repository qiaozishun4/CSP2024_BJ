#include<bits/stdc++.h>
using namespace std;

int T,n,m,cnt,x,y,k,f;
int t[2010][2010];
char a[2010][2010];
int dx[100]={0,1,0,-1};
int dy[100]={1,0,-1,0};
void dfs(int x,int y,int f,int b){
	if(t[x][y]==0){
		cnt++;
	}
	t[x][y]++;
	if(b>=k){
		return ;
	}
	if(x+dx[f]<=n&&y+dy[f]<=m&&x+dx[f]>=1&&y+dy[f]>=1&&a[x+dx[f]][y+dy[f]]=='.'){
		dfs(x+dx[f],y+dy[f],f,b+1);
	}
	else{
		dfs(x,y,(f+1)%4,b+1);
	}
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		cin >> x >> y >> f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> a[i][j];
			}
		}
		dfs(x,y,f,0);
		cout << cnt << endl;
		cnt=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				a[i][j]='x';
				t[i][j]=0;
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
