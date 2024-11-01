#include<bits/stdc++.h>
using namespace std;
bool mp[1005][1005];
bool vis[1005][1005];
int n,m,k;
void dfs(int x,int y,int d,int s){
	vis[x][y]=1;
	if(s==k){
		return ;
	}
	if(d==0){
		if(y+1>m||mp[x][y+1]){
			dfs(x,y,(d+1)%4,s+1);
			return ;
		}
		else{
			dfs(x,y+1,d,s+1);
			return ;
		}
	}
	else if(d==1){
		if(x+1>n||mp[x+1][y]){
			dfs(x,y,(d+1)%4,s+1);
			return ;
		}
		else{
			dfs(x+1,y,d,s+1);
			return ;
		}
	}
	else if(d==2){
		if(y-1<1||mp[x][y-1]){
			dfs(x,y,(d+1)%4,s+1);
			return ;
		}
		else{
			dfs(x,y-1,d,s+1);
			return ;
		}
	}
	else if(d==3){
		if(x-1<1||mp[x-1][y]){
			dfs(x,y,(d+1)%4,s+1);
			return ;
		}
		else{
			dfs(x-1,y,d,s+1);
			return ;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		char c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c=='x') mp[i][j]=1;
				else mp[i][j]=0;
			}	
		}
		dfs(x,y,d,0);
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
