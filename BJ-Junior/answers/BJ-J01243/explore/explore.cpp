#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char a[N][N];
bool b[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	int n,m,k,x,y,d,cnt;
	cin>>T;
	while(T--){
		memset(b,0,sizeof(b));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		b[x][y]=1;
		cnt=1;
		for(int i=1;i<=k;i++){
			int kx=x+dx[d];
			int ky=y+dy[d];
			if(kx>n || kx<1 || ky>m || ky<1 || a[kx][ky]=='x') d=(d+1)%4;
			else{
				x=kx;
				y=ky;
				if(!b[x][y]){
					b[x][y]=1;
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
