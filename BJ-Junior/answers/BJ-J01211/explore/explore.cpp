//编译有误
#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	int i,j;
	while(t--){
		long long n,m,k;
		cin>>n>>m>>k;
		string a[1010][1010];
		for(i=1;i<n;i++)
			for(j=1;j<m;j++)
				cin>>a[i][j];
		long long x,y,d;
		cin>>x>>y>>d;
		long long ans;
		while(k--){
			if(d==0&&1<=x&&x<=n&&1<=(y+1)&&(y+1)<=m&&a[x][y+1]=='.'){
				y++;
				ans++;
			}
			else{
				if(d==1&&1<=(x+1)&&(x+1)<=n&&1<=y&&y<=m&&a[x+1][y]!=='.'){
					x++;
					ans++;
				}
				else{
					if(d==2&&1<=x&&x<=n&&1<=(y-1)&&(y-1)<=m&&a[x][y-1]=='.'){
						y--;
						ans++;
					}
					else{
						if(d==1&&1<=(x-1)&&(x-1)<=n&&1<=y&&y<=m&&a[x-1][y]=='.'){
							x--;
							ans++;
						}
						else
							d=(d+1)%4;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
