#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int t,n,m,k;
int sx,sy,d,ans;
char a[N][N];
bool vis[N][N];
void dfs(int x,int y,int p,int ttk){
	if(ttk>=k) return ;
	if(p==0){ y++;
		if(x<1||x>n||y<1||y>m||a[x][y]=='x')
			dfs(x,y-1,(p+1)%4,ttk+1);
		else if(vis[x][y]) dfs(x,y,p,ttk+1);
		else{ans++; vis[x][y]=1; dfs(x,y,p,ttk+1);}
	} else if(p==1){ x++;
		if(x<1||x>n||y<1||y>m||a[x][y]=='x')
			dfs(x-1,y,(p+1)%4,ttk+1);
		else if(vis[x][y]) dfs(x,y,p,ttk+1);
		else{ans++; vis[x][y]=1; dfs(x,y,p,ttk+1);}
	} else if(p==2){ y--;
		if(x<1||x>n||y<1||y>m||a[x][y]=='x')
			dfs(x,y+1,(p+1)%4,ttk+1);
		else if(vis[x][y]) dfs(x,y,p,ttk+1);
		else{ans++; vis[x][y]=1; dfs(x,y,p,ttk+1);}
	} else if(p==3){ x--;
		if(x<1||x>n||y<1||y>m||a[x][y]=='x')
			dfs(x+1,y,(p+1)%4,ttk+1);
		else if(vis[x][y]) dfs(x,y,p,ttk+1);
		else{ans++; vis[x][y]=1; dfs(x,y,p,ttk+1);}
	} 
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){ ans=1;
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&sx,&sy,&d);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		dfs(sx,sy,d,0); printf("%d\n",ans);
	}
	return 0;
}
