#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10;
int xi0,yi0,di0;
int t,n,m,k,ans;
char a[maxn][maxn];
bool flag[maxn][maxn];
bool inb(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>xi0>>yi0>>di0;
		for(int i=1;i<=maxn;i++){
			for(int j=1;j<=maxn;j++){
				flag[i][j]=false;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		ans=1;
		int nx=xi0,ny=yi0,nd=di0,dx,dy;
		int cnt=1;
		flag[nx][ny]=true;
		while(k--){
			if(nd==0){
				dx=nx;
				dy=ny+1;
			}
			if(nd==1){
				dx=nx+1;
				dy=ny;
			}
			if(nd==2){
				dx=nx;
				dy=ny-1;
			}
			if(nd==3){
				dx=nx-1;
				dy=ny;
			}
			if(!inb(dx,dy)||a[dx][dy]=='x'){
				nd=(nd+1)%4;
				continue;
			}
			if(inb(dx,dy)&&!flag[dx][dy]&&a[dx][dy]=='.'){
				nx=dx;
				ny=dy;
				flag[dx][dy]=true;
				cnt++;
			}
			else{
				nx=dx;
				ny=dy;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
