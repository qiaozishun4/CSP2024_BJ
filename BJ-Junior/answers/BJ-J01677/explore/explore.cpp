#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int v[1005][1005];
int ans,n,m;
int kk,yy,xx;
int d1,q;
int dfs(int xa,int ya,int d,int k){
	if(k==0){
		
		return 0;
	}
	if(d==0){
		if(1<=ya+1&&ya+1<=m&&a[xa][ya+1]=='.'){
			
				v[xa][ya+1]++;
				dfs(xa,ya+1,d,k-1);
		}
		else{

			if(v[xa][ya]==0)v[xa][ya]++;
			dfs(xa,ya,(d+1)%4,k-1);
		}
	}
	if(d==1){
		if(1<=xa+1&&xa+1<=n&&a[xa+1][ya]=='.'){
				
				v[xa+1][ya]++;
				dfs(xa+1,ya,d,k-1);
		}
		else{

			if(v[xa][ya]==0)v[xa][ya]++;
			dfs(xa,ya,(d+1)%4,k-1);
		}
	}if(d==2){
		if(1<=ya-1&&ya-1<=m&&a[xa][ya-1]=='.'){
				
				v[xa][ya-1]++;
				dfs(xa,ya-1,d,k-1);

		}
		else{

			if(v[xa][ya]==0)v[xa][ya]++;
			dfs(xa,ya,(d+1)%4,k-1);
		}
	}if(d==3){
		if(1<=xa-1&&xa-1<=n&&a[xa-1][ya]=='.'){
				
				v[xa-1][ya]++;
				dfs(xa-1,ya,d,k-1);
		}
		else{
			if(v[xa][ya]==0)v[xa][ya]++;
			dfs(xa,ya,(d+1)%4,k-1);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n>>m>>kk>>xx>>yy>>d1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
        v[xx][yy]=1;
		dfs(xx,yy,d1,kk);

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(v[i][j]>=1)ans++;
			}
		}
		
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				v[i][j]=0;
				a[i][j]=0;
			}
		}
		ans=0;
	}
	return 0;
}
