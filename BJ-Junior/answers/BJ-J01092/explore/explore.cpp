#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans;
char c[1010][1010];

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>c[i][j];
		while(k>0)
		{
			if((d==0&&c[x][y+1]=='.')&&((x>=1&&x<=n)&&(y+1>=1&&y+1<=m)))
			{
				c[x][y]='x';
				ans++;
				y++;
				k--;
			}
			else if((d==1&&c[x+1][y]=='.')&&((x+1>=1&&x+1<=n)&&(y>=1&&y<=m)))
			{
				c[x][y]='x';
				ans++;
				x++;
				k--;
			}
			else if((d==2&&c[x][y-1]=='.')&&((x>=1&&x<=n)&&(y-1>=1&&y-1<=m)))
			{
				c[x][y]='x';
				ans++;
				y--;
				k--;
			}
			else if((d==3&&c[x-1][y]=='.')&&((x-1>=1&&x-1<=n)&&(y>=1&&y<=m)))
			{
				c[x][y]='x';
				ans++;
				x--;
				k--;
			}
			else
			{
				d=(d+1)%4;
				k--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
