#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
int T;
int n,m,k;
int xa,ya,da;
char a[N+5][N+5];
bitset<N+5> vis[N+5];
struct Node{
	int x,y;
	int d;
	int step;
};
void init(){
	for(int i=1;i<=n;i++)
		vis[i]=0;
	return ;
}
int nextx(int x,int d){
	if(d==0)
		return x;
	if(d==1)
		return x+1;
	if(d==2)
		return x;
	if(d==3)
		return x-1;
	return -1;
}
int nexty(int y,int d){
	if(d==0)
		return y+1;
	if(d==1)
		return y;
	if(d==2)
		return y-1;
	if(d==3)
		return y;
	return -1;
}
void dfs(int x,int y,int d,int step){
	cout<<"dfs "<<x<<","<<y<<"\n";
	cout<<"a"<<endl;
	vis[x][y]=1;
	if(step==k)
		return ;
	cout<<"b"<<endl;
	int dx=nextx(x,d);
	int dy=nexty(y,d);
	cout<<"c"<<endl;
	if(dx<1||dx>n||dy<1||dy>m||a[dx][dy]=='x'){
		cout<<"go1"<<endl;
		dfs(x,y,(d+1)%4,step+1);
	}
	else{
		cout<<"go2 "<<dx<<","<<dy<<endl;
		dfs(dx,dy,d,step+1);
	}
	return ;
}
void bfs(int sx,int sy,int sd,int sstep){
	queue<Node>q;
	q.push({sx,sy,sd,sstep});
	while(!q.empty()){
		Node u=q.front();
		q.pop();
		vis[u.x][u.y]=1;
		if(u.step==k)
			return ;
		int dx=nextx(u.x,u.d);
		int dy=nexty(u.y,u.d);
		if(dx<1||dx>n||dy<1||dy>m||a[dx][dy]=='x')
			q.push({u.x,u.y,(u.d+1)%4,u.step+1});
		else
			q.push({dx,dy,u.d,u.step+1});
	}
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>xa>>ya>>da;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		init();
		bfs(xa,ya,da,0);
		int res=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vis[i][j])
					res++;
		cout<<res<<"\n";
	}
	return 0;
}
//LXT5201314