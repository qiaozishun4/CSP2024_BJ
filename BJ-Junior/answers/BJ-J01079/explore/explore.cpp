#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    for(int z=1;z<=t;z++){
		int n,m,k,x,y,d,sum=0,a[1005][1005]={0};
		cin>>n>>m>>k>>x>>y>>d;
		char c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c=='.') a[i][j]=0;
				else a[i][j]=-1;
			}
		}
		a[x][y]=1;
		for(int i=1;i<=k;i++){
			if(a[x+dx[d]][y+dy[d]]!=-1&&0<x+dx[d]&&x+dx[d]<=n&&0<y+dy[d]&&y+dy[d]<=m){
				x+=dx[d];
				y+=dy[d];
				a[x][y]=1;
			}
			else{
				d=(d+1)%4;
			}
			//cout<<x<<" "<<y<<" "<<d<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==1)sum++;
			}
		}
		cout<<sum<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
