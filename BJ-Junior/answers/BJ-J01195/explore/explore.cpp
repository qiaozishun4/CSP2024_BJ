#include<bits/stdc++.h>
#define ll long long
using namespace std;
int x,y,d;
bool mp[1005][1005];
bool vis[1005][1005];
int n,m,k;
int nx[4]={0,1,0,-1};
int ny[4]={1,0,-1,0};
bool check(int xt,int yt){
	if(xt>n||yt>m||xt<1||yt<1)return 0;
	if(!mp[xt][yt])return 0;
	return 1;
}
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char x;
				cin>>x;
				mp[i][j]=(x=='.');
			}
		}
		int cnt=1;vis[x][y]=1;
		for(int i=1;i<=k;i++){
			if(check(x+nx[d],y+ny[d])){
				x+=nx[d];y+=ny[d];
			}
			else d=(d+1)%4;
			if(!vis[x][y])cnt++;
			vis[x][y]=1;
		}
		cout<<cnt<<endl;
	}
	return 0;
}