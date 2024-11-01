#include<bits/stdc++.h>
using namespace std;
int n,m,s,book[1005][1005],path;
char a[1005][1005];
void dfs(int x,int y,int d,int step){
	if(step==s+1){
		printf("%d\n",path);
		return;
	}
	if(book[x][y]==0){
		book[x][y]=1;
		path++;
	}
	if(d==0){
		if(y<m&&a[x][y+1]=='.')dfs(x,y+1,d,step+1);
		else if(y==m||a[x][y+1]=='x')dfs(x,y,1,step+1);
	}
	else if(d==1){
		if(x<n&&a[x+1][y]=='.')dfs(x+1,y,d,step+1);
		else if(x==n||a[x+1][y]=='x')dfs(x,y,2,step+1);
	}
	else if(d==2){
		if(y>1&&a[x][y-1]=='.')dfs(x,y-1,d,step+1);
		else if(y==1||a[x][y-1]=='x')dfs(x,y,3,step+1);
	}
	else if(d==3){
		if(x>1&&a[x-1][y]=='.')dfs(x-1,y,d,step+1);
		else if(x==1||a[x-1][y]=='x')dfs(x,y,0,step+1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int u,v,w;
		path=0;
		memset(book,0,sizeof book);
		memset(a,0,sizeof a);
		cin>>n>>m>>s>>u>>v>>w;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				cin>>a[j][k];
		dfs(u,v,w,0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
