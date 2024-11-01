#include <bits/stdc++.h>
using namespace std;
char c;
int ans,k,n,m,x,y,d,t;
int vis[1005][1005],mapp[1005][1005],dxy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct node{
	int x,y;
	int d,cnt;
};
void bfs(){
	ans=0;
	memset(vis,0,sizeof(vis));
	queue<node> q;
	node v,u;
	v.x=x;
	v.y=y;
	v.d=d;
	v.cnt=0;
	q.push(v);
	int dx,dy;
	while(true){
		v=q.front();q.pop();
		if(vis[v.x][v.y]==0)  ans++;
		//cout<<v.x<<' '<<v.y<<' '<<v.d<<endl;
		vis[v.x][v.y]=1;
		if(v.cnt==k) {cout<<ans<<endl;return ;}
		dx=v.x+dxy[v.d][0],dy=dxy[v.d][1]+v.y;
		//cout<<dx<<' '<<dy<<endl;
		if(mapp[dx][dy] ||dx>n || dx<=0|| dy>m || dy<=0){
			u.d=(v.d+1)%4;
			u.cnt=v.cnt+1;
			u.x=v.x;
			u.y=v.y;
			q.push(u);
		} else{
			u.d=v.d;
			u.cnt=v.cnt+1;
			u.x=dx;
			u.y=dy;
			q.push(u);		
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c=='.') mapp[i][j]=0;
				else mapp[i][j]=1;
			}
		}

		bfs();
	}
	return 0;
}
