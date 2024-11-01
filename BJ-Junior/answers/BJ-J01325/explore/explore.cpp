#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
string s[N];
int vis[N][N],n,m,k,d,x,y,sum,T;
int xx[]={0,1,0,-1},yy[]={1,0,-1,0};
bool check(int x,int y,int k){
	if( x>=1 && x<=n && y>=1 && y<=m){
		return s[x][y]=='.';
	}
	else return 0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++){
			cin>>s[i];
			s[i]=" "+s[i];
		}
		k+=1;
		while(k--){
			if(vis[x][y]==0){
				sum++;
				vis[x][y]=1;
			}
			if(check(x+xx[d],y+yy[d],k)){
				x+=xx[d];
				y+=yy[d];
			}
			else d=(d+1)%4;
		}
		printf("%d\n",sum);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)vis[i][j]=0;
		sum=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}