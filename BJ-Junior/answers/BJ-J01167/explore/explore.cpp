#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		char a[n+1][m+1];
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		int ans=0;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(a[x][y+1]<1||a[x][y+1]>n||a[x][y+1]>m||a[x][y+1]=='x'){
					d=1;
					continue;
				}
				else{
					ans++;
					y=y+1;
					continue;
				}
			}
			if(d==1){
				if(a[x+1][y]<1||a[x+1][y]>n||a[x+1][y]>m||a[x+1][y]=='x'){
					d=2;

					continue;
				}
				else{

					ans++;
					x=x+1;
					continue;
				}
			}
			if(d==2){
				if(a[x][y-1]<1||a[x][y-1]>n||a[x][y-1]>m||a[x][y-1]=='x'){
					d=3;

					continue;
				}
				else{

					ans++;
					y=y-1;
					continue;
				}
			}
			else{
				if(a[x-1][y]<1||a[x-1][y]>n||a[x-1][y]>m||a[x-1][y]=='x'){
					d=0;

					continue;
				}
				else{

					ans++;
					x=x-1;
					continue;
				}
			}
		}
		cout<<ans<<"\n";

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}