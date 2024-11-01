#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char a[N][N];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
map<int,int>mp;
char read(){
	char c='#';
	while(!(c=='.'||c=='x'))scanf("%c",&c);
	return c;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		mp.clear();
		int n,m,k,x,y,d,i,j;
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(i=1;i<=n;++i)for(j=1;j<=m;++j)a[i][j]=read();
		mp[x*1005+y]=1;
		for(i=1;i<=k;++i){
			if(!(x+dx[d]>=1&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m)){
				d=(d+1)%4;
				continue;
			}
			if(a[x+dx[d]][y+dy[d]]!='.'){
				d=(d+1)%4;
				continue;
			}
			x=x+dx[d];
			y=y+dy[d];
			mp[x*1005+y]=1;
		}
		printf("%d\n",mp.size());
	}
	return 0;
}
