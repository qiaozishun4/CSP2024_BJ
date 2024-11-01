#include <bits/stdc++.h>
using namespace std;
const int dir[15][3]={{0,1},{1,0},{0,-1},{-1,0}};
int t,n,m,k,x,y,d,ans,mp[1005][1005],vis[1005][1005];
char c; 
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t,++t;
	while(--t){
		cin>>n>>m>>k>>x>>y>>d,ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>c;
				if(c=='x') mp[i][j]=1;
				else mp[i][j]=0;
				vis[i][j]=0;
			}
		}
		for(int i=1;i<=k+1;++i){
			int tgtx=x+dir[d][0],tgty=y+dir[d][1];
//			cout<<"target: "<<tgtx<<", "<<tgty<<"\n";
			if(!vis[x][y]) ++ans,vis[x][y]=1;
			if(i==k+1) break;
			if(tgtx>n||tgtx<=0||tgty>m||tgty<=0||mp[tgtx][tgty]){
				d=(d+1)%4;
//				cout<<"blocked.\n";
				continue;
			}
//			cout<<"passed.\n";
			x=tgtx,y=tgty;
		}
		cout<<ans<<"\n";
	}
    return 0;
}