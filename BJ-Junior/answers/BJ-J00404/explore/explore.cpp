#include<bits/stdc++.h>
using namespace std;
bool check(long long u,long long v,long long n,long long m)
{
	return u<=n&&v<=m&&u>=1&&v>=1;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin>>t;
	while(t--){
		long long n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		char c[1005][1005];
		bool vis[1005][1005]={};
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		long long cnt=1;
		vis[x][y]=true;
		for(long long i=1;i<=k;i++){
			
			int u,v;
			if(d==0) u=x,v=y+1;
			if(d==1) u=x+1,v=y;
			if(d==2) u=x,v=y-1;
			if(d==3) u=x-1,v=y;
			if(check(u,v,n,m)&&c[u][v]=='.'){
				x=u,y=v;
				if(!vis[u][v]){
					vis[u][v]=true;
					cnt++;
				}
			}else{
				d=(d+1)%4;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
