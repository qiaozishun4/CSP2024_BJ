#include<bits/stdc++.h>
using namespace std;
string a[1005];
bool b[1005][1005];
int T,n,m,k,x,y,d;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		b[x][y]=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		while(k--)
		{
			int fx=x,fy=x;
			fx=x;
			fy=y;
			if(d==0) fy+=1;
			else if(d==1) fx+=1;
			else if(d==2) fy-=1;
			else fx-=1;
			if(fx>=1 && fx<=n && fy>=1 && fy<=m && a[fx][fy-1]=='.')
			{
				x=fx;
				y=fy;
				b[x][y]=1;
			}
			else d=(d+1)%4;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j])
				{
					ans++;
					b[i][j]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
