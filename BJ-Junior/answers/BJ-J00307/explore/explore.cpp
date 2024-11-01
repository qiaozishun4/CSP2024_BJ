#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m,d,x,y,k,ans,vis[2010][2010];
char a[2010][2010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) cin>>a[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) vis[i][j]=0;
		for(int i=1;i<=k;i++){
			vis[x][y]=1;
			if(d==0){
				if(y+1>=1&&y+1<=m&&a[x][y+1]=='.') y++;
				else d=1;
			}else if(d==1){
				if(x+1>=1&&x+1<=n&&a[x+1][y]=='.') x++;
				else d=2;
			}else if(d==2){
				if(y-1>=1&&y-1<=m&&a[x][y-1]=='.') y--;
				else d=3;
			}else if(d==3){
				if(x-1>=1&&x-1<=n&&a[x-1][y]=='.') x--;
				else d=0;
			}
		}vis[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vis[i][j]!=0) ans++;
		cout<<ans<<endl;
	}
	return 0;
}