#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1010][1010];
int n,m,cnmt,b[1010];
struct node{
	int x,y;
};
bool check(int x,int y){
	return x>0&&x<=n&&y>0&&y<=m&&a[x][y]!='x';
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int k,x0,y0,d0,nowd,ans=0,step=0,t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof vis);
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		step=0,ans=0;
		nowd=d0;
		queue<node> q;
		q.push({x0,y0});
		while(!q.empty()){
			if(step==k) break;
			node t=q.front();
			q.pop();
			
			int xx=t.x+d[nowd][0];
			int yy=t.y+d[nowd][1];
			if(check(xx,yy)&&!vis[xx][yy]){
				step++,ans++;
				q.push({xx,yy});
				vis[t.x][t.y]=1;
			//	cout<<1<<endl;
			}
			else if(check(xx,yy)&&vis[xx][yy]){
				step++;
				q.push({xx,yy});
				vis[t.x][t.y]=1;
			}
			else{
				nowd=(nowd+1)%4,step++;
				q.push({t.x,t.y});
			//	cout<<0<<endl;
			}
			
		}b[++cnmt]=ans+1;
	}
	for(int i=1;i<=cnmt;i++) cout<<b[i]<<endl;
	return 0;
}
