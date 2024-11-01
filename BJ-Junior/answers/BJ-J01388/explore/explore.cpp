#include<bits/stdc++.h>
using namespace std;
int c[1010][1010];
int n,m,k,cnt=0;
char a[1010][1010];
bool b[1010][1010];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y,int d,int k){
	if(b[x][y]!=1){
		cnt++;
	}
	b[x][y]=1;
	if(k==0||d==c[x][y])return;
	c[x][y]=d;
	if(y+dy[d]<1||x+dx[d]<1||y+dy[d]>m||x+dx[d]>n||a[x+dx[d]][y+dy[d]]=='x'){
		d=(d+1)%4;
		dfs(x,y,d,k-1);
	}
	else{
		x=x+dx[d];
		y=y+dy[d];
		dfs(x,y,d,k-1);
	}
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(c,-1,sizeof(c));
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dfs(x,y,d,k);
		cout<<cnt<<endl;
		cnt=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	return 0;
}
