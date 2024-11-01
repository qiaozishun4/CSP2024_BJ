#include<bits/stdc++.h>
using namespace std;
char a[1007][1007];
int ans[7];
int cnt=1;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T ;
	for(int qw=1;qw<=T;qw++)
	{
		int n,m,k;
		int mid=0;
		cin >> n >> m >> k ;
		int x,y,d;
		cin >> x >> y >> d ;
		d=d%4;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin >> a[i][j] ;
			}
		}
		a[x][y]='q';
		mid++;
		//
		for(int i=1;i<=k;i++)
		{
			if(d==0){ // dong
				if(a[x][y+1]=='.'&&y+1<=m){
					a[x][++y]='q';
					mid++;
				}
				if(a[x][y+1]=='q'&&y+1<=m){
					y++;
				}
				if(a[x][y+1]=='x'||y+1>m) d=1;
			}
			else if(d==1){ // nan
				if(a[x+1][y]=='.'&&x+1<=n){
					a[++x][y]='q';
					mid++;
				}
				if(a[x+1][y]=='q'&&x+1<=n){
					x++;
				}
				if(a[x+1][y]=='x'||x+1>n) d=2;
			}
			else if(d==2){ // xi
				if(a[x][y-1]=='.'&&y-1>=1){
					a[x][--y]='q';
					mid++;
				}
				if(a[x][y-1]=='q'&&y-1>=1){
					y--;
				}
				if(a[x][y-1]=='x'||y-1<1) d=3;
			}
			else if(d==3){ // bei
				if(a[x-1][y]=='.'&&x-1>=1){
					a[--x][y]='q';
					mid++;
				}
				if(a[x-1][y]=='q'&&x-1>=1){
					x--;
				}
				if(a[x-1][y]=='x'||x-1<1) d=0;
			}
		}
		//
		ans[qw]=mid;
	}
	for(int i=1;i<=T;i++) cout << ans[i] << endl ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
