#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,x,y,d,tx,ty,c;
bool arrive1[1001][1001];
int direc[4][2]={0,1,1,0,0,-1,-1,0};
char map1[1001][1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%lld",&T);
	for(int i=1;i<=T;i++){
		scanf("%lld %lld %lld",&n,&m,&k);
		scanf("%lld %lld %lld",&x,&y,&d);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
			cin>>map1[i][j];
			arrive1[i][j]=0;
		}
		arrive1[x][y]=1;
		for(int i=1;i<=k;i++){
			tx=x+direc[d][0],ty=y+direc[d][1];
			if(map1[tx][ty]=='x'||tx>n||ty>m||tx<1||ty<1) d=(d+1)%4;
			else arrive1[tx][ty]=1,x=tx,y=ty;
		}
		c=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) c+=arrive1[i][j];
		printf("%lld\n",c);
	}
	return 0;
}
