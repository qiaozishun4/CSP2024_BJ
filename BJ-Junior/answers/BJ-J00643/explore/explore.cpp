#include<bits/stdc++.h>
#define N 1100
using namespace std;
bool ma[N][N],vis[N][N];
bool check(int d,int xx,int yy){
	int x=xx,y=yy;
	if(d==0){
		y++;
		if(ma[x][y]==0){
			return 1;
		}
		return 0;
	}
	if(d==1){
		x++;
		if(ma[x][y]==0){
			return 1;
		}
		return 0;
	}
	if(d==2){
		y--;
		if(ma[x][y]==0){
			return 1;
		}
		return 0;
	}
	if(d==3){
		x--;
		if(ma[x][y]==0){
			return 1;
		}
		return 0;
	}
	return 1;
}
void solve(){
	int n,m,k,x,y,d;
	cin>>n>>m>>k>>x>>y>>d;
	memset(ma,0,sizeof(ma));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char x;
			cin>>x;
			if(x=='.'){
				ma[i][j]=1;
			}
		}
	}
	int ans=1;
	while(k>0){
		vis[x][y]=1;
		if(check(d,x,y)){
			while(check(d,x,y) && k>0){
				k--;
				d=(d+1)%4;
			}	
		}else{
			k--;
			if(d==0){
				y++;
				if(!vis[x][y]){
					ans++;
				}
			}
			if(d==1){
				x++;
				if(!vis[x][y]){
					ans++;
				}
			}
			if(d==2){
				y--;
				if(!vis[x][y]){
					ans++;
				}
			}
			if(d==3){
				x--;
				if(!vis[x][y]){
					ans++;
				}
			}			
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}