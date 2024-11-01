#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a ; i<=b ; i++)
using namespace std;
int t,n,m,k,cnt;
int sx,sy,d0;
char g[1005][1005];
bool vis[1005][1005];
bool check(int x,int y,int d){
	if(d == 0) y++;
	else if(d == 1) x++;
	else if(d == 2) y--;
	else x--;
	if(x<1||x>n||y<1||y>m||g[x][y] == 'x') return 0;
	else return 1;
}
void dfs(int x,int y,int step,int d){
	if(!vis[x][y] && x>=1 && x<=n && y>=1 && y<=m) cnt++;
	vis[x][y] = 1;
	if(step>k){
		return ;
	}
	if(check(x,y,d)){
		if(d == 0) dfs(x,y+1,step+1,d);
		else if(d == 1) dfs(x+1,y,step+1,d);
		else if(d == 2) dfs(x,y-1,step+1,d);
		else dfs(x-1,y,step+1,d);
	}else{
		while(1){
			d = (d+1)%4;
			step++;
			if(step>k) return ;
			if(check(x,y,d)){
				if(d == 0) dfs(x,y+1,step+1,d);
				else if(d == 1) dfs(x+1,y,step+1,d);
				else if(d == 2) dfs(x,y-1,step+1,d);
				else dfs(x-1,y,step+1,d);
				break;
			}
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>sx>>sy>>d0;
		f(i,1,n){
			f(j,1,m){
				cin>>g[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
			cnt = 0;
			dfs(sx,sy,1,d0);
			int cnt = 0;
		f(i,1,n){
			f(j,1,m){
				if(vis[i][j] == 1) cnt++;
			}
		}
		cout<<cnt<<endl;
		
	}
    return 0;
}
