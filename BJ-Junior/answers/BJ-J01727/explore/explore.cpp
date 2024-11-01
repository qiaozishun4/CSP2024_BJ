#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
typedef struct point{
	int x,y,d,step;
}Point;
queue<Point>q;
set<pair<int,int>>vis;
char mp[1010][1010];
int T,n,m,kkk,fx,fy,d;
void bfs(){
	vis.clear();
	while(!q.empty())q.pop();
	q.push({fx,fy,d,0});
	vis.insert({fx,fy});
	while(!q.empty()){
		Point k=q.front();
		vis.insert({k.x,k.y});
		//printf("%d %d %d %d\n",k.x,k.y,k.d,k.step);
		q.pop();
		if(k.step>=kkk){
			printf("%ld\n",vis.size());
			return ;
		}
		int xx=k.x+dx[k.d],yy=k.y+dy[k.d];
		if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]=='x')q.push({k.x,k.y,(k.d+1)%4,k.step+1});
		else{
			//printf("!!!%d %d\n\n",xx,yy);
			q.push({xx,yy,k.d,k.step+1});
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&kkk);
		scanf("%d%d%d",&fx,&fy,&d);
		char c=getchar();
		while(c!='.'&&c!='x')c=getchar();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				mp[i][j]=c;
				//cout<<c;
				c=getchar();
				if(!(i==n&&j==m))
					while(c!='.'&&c!='x')c=getchar();
			}
		bfs();
	}
	return 0;
}
