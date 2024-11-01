#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int xz,yz,dz;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char mnp[1010][1010];
bool vis[1010][1010];
bool chk(int x,int y){
	if (x<1 or y<1 or x>n or y>m)return 0;
	if (mnp[x][y]=='x')return 0;
	return 1;
}
void q(){
	int ans=0;
	memset(mnp,0,sizeof(mnp));
	memset(vis,0,sizeof(vis));
	scanf("%d%d%d%d%d%d",&n,&m,&k,&xz,&yz,&dz);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>mnp[i][j];
		}
	}
	int x=xz,y=yz,d=dz;
	for (int i=1;i<=k;i++){
		int nx=x+dx[d],ny=y+dy[d];
		if (vis[x][y]==0){
			ans++;
			vis[x][y]=1;
			mnp[x][y]='v';
		}
		if (chk(nx,ny)){
			x=nx,y=ny;
			//printf("{1}");
		}else{
			//printf("{2}");
			d=(d+1)%4;
		}
		if (vis[x][y]==0){
			ans++;
			vis[x][y]=1;
			mnp[x][y]='v';
		}
	}
	/*for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			printf("%c",mnp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n",ans);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		q();
	}
	fclose(stdin);
	fclose(stdout);
}
