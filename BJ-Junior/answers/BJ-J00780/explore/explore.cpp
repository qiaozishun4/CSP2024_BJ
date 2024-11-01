#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int T;
int n,m,k;
int x,y,d;
int cnt;
bool ma[N][N];
int ap[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while(T--){
		cnt=0;
		memset(ma,0,sizeof ma);
		memset(ap,0,sizeof ap);
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char c;
				cin >> c;
				ma[i][j]=(c=='.')?false:true;
			}
		ap[x][y]=3;
		while(k--){
			x+=dx[d],y+=dy[d];
			if(ma[x][y]==true||x<1||x>n||y<1||y>m)
				x-=dx[d],y-=dy[d],d=(d+1)%4;
			else ap[x][y]=3;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(ap[i][j]==3) cnt++;
		cout << cnt << endl;

	}
	return 0;
}