#include<bits/stdc++.h>
using namespace std;
int t,ans=1;
bool vis[1005][1005];
char a[1005][1005];
int jdsj(int n,int m,int x3,int y3,int d3,int k3,int ans){
	if(k3==0){
		cout<<ans<<endl;
		return 0;
	}
	vis[x3][y3]=1;
	k3--;
	if(d3==0){
		if(a[x3][y3+1]=='.'&&1<=x3&&x3<=n&&1<=y3&&y3<=m){
			if(vis[x3][y3+1]==0){
				ans++;
			}
			jdsj(n,m,x3,y3+1,d3,k3,ans);
		}else{
			d3++;
			d3%=4;
			jdsj(n,m,x3,y3,d3,k3,ans);
		}
	}else if(d3==1){
		if(a[x3+1][y3]=='.'&&1<=x3&&x3<=n&&1<=y3&&y3<=m){
			if(vis[x3+1][y3]==0){
				ans++;
			}
			jdsj(n,m,x3+1,y3,d3,k3,ans);
		}else{
			d3++;
			d3%=4;
			jdsj(n,m,x3,y3,d3,k3,ans);
		}
	}else if(d3==2){
		if(a[x3][y3-1]=='.'&&1<=x3&&x3<=n&&1<=y3&&y3<=m){
			if(vis[x3][y3-1]==0){
				ans++;
			}
			jdsj(n,m,x3,y3-1,d3,k3,ans);
		}else{
			d3++;
			d3%=4;
			jdsj(n,m,x3,y3,d3,k3,ans);
		}
	}else if(d3==3){
		if(a[x3-1][y3]=='.'&&1<=x3&&x3<=n&&1<=y3&&y3<=m){
			if(vis[x3-1][y3]==0){
				ans++;
			}
			jdsj(n,m,x3-1,y3,d3,k3,ans);
		}else{
			d3++;
			d3%=4;
			jdsj(n,m,x3,y3,d3,k3,ans);
		}
	}
	return 0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=0;
			}
		}
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		jdsj(n,m,x,y,d,k,ans);
	}
	return 0;
}
