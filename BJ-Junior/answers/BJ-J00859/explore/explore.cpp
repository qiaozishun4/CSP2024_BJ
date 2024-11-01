#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char mp[1005][1005];
bool vis[1005][1005];
int n,m,k;
bool check(int a,int b){
	return a>=1 and a<=n and b<=m and b>=1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		int num=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				vis[i][j]=false;
			}
		}
		vis[x0][y0]=true;
		while(k--){
			int x1=x0+dx[d0];
			int y1=y0+dy[d0];
			if(check(x1,y1) and mp[x1][y1]!='x'){
				x0=x1;
				y0=y1;
				if(!vis[x0][y0]){num++;}
				vis[x0][y0]=true;
			}
			else d0=(d0+1)%4;
		}
		cout<<num<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
