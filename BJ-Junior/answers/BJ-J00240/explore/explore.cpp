#include <bits/stdc++.h>
using namespace std;
bool b[1005][1005];
char c[1005][1005];
int h[4]={0,1,0,-1},l[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d;
	cin>>t;
	while(t--){
		memset(b,0,sizeof(b));
		cin>>n>>m>>k>>x>>y>>d;
		b[x][y] = 1;
		int ans = 1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)cin>>c[i][j];
		while(k--){
			if(h[d]+x>0&&h[d]+x<=n&&l[d]+y>0&&l[d]+y<=m&&c[h[d]+x][l[d]+y]=='.'){
				x+=h[d],y+=l[d];
				if(!b[x][y]){
					b[x][y]=1;
					ans++;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
}
