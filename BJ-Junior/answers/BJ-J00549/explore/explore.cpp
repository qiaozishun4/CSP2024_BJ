#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int a[N][N];
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,m,k;
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char ch;
				cin>>ch;
				if(ch=='x') a[i][j]=1;
			}
	    }
	    int ans=1;
	    a[x0][y0]=2;
	    for(int i=1;i<=k;i++){
			if(x0+d[d0][0]>0&&x0+d[d0][0]<=n&&y0+d[d0][1]>0&&y0+d[d0][1]<=m&&a[x0+d[d0][0]][y0+d[d0][1]]!=1){
				x0+=d[d0][0];
				y0+=d[d0][1];
				if(a[x0][y0]!=2){
					ans++;
					a[x0][y0]=2;
				}
			}else{
				d0=(d0+1)%4;
			}
		}
		cout<<ans<<endl;
    }
	return 0;
}