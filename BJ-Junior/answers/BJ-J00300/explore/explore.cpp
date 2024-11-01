#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
int h[1001][1001];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,d,k,nx,ny,ans;
	cin>>t;
	int x,y;
	
	while(t--){
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=1000;j++){
				h[i][j]=0;
			}
		}
		cin>>n>>m>>k>>x>>y>>d;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&a[i][j]);
			}
		}
		h[x][y]=1;
		while(k){
			nx=x+dx[d];
			ny=y+dy[d];
			while(nx<1 || nx>n || ny<1 || ny>m || a[nx][ny]=='x'){
				d=(d+1)%4;
				nx=x+dx[d];
				ny=y+dy[d];
				k--;
				if(k<=0)break;
			}
			if(k<=0)break;
			x=nx;
			y=ny;
			h[x][y]=1;
			k--;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=h[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	
}
