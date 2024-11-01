#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,k,x,y,d,ans;
char a[1005][1005];

int dfs(int x,int y,int d,int k){
	if(k==0) return 1;
	int aa=-1;
	if(d==0&&y+1<=m&&a[x][y+1]=='.') aa=dfs(x,y+1,0,k-1)+1;
	else if(d==1&&x+1<=n&&a[x+1][y]=='.') aa=dfs(x+1,y,1,k-1)+1;
	else if(d==2&&y-1>=1&&a[x][y-1]=='.') aa=dfs(x,y-1,2,k-1)+1;
	else if(d==3&&x-1>=1&&a[x-1][y]=='.') aa=dfs(x-1,y,3,k-1)+1;
	if(aa==-1) return dfs(x,y,(d+1)%4,k-1);
	return aa;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		cout<<dfs(x,y,d,k)<<"\n";
	}
	return 0;
}
