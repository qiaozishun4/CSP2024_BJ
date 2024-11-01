#include <bits/stdc++.h>
using namespace std;
int f[2000][2000];
char a[2000];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,x,y,k,d;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			for(int j=0;j<m;j++)
			{
				if(int(a[j])!='x')
					f[i][j+1]=1;
			}
		}
		int s=1,b,c;
		f[x][y]=2;
		while(k--)
		{
			b=x;
			c=y;
			if(d==0)
				c=y+1;
			if(d==1)
				b=x+1;
			if(d==2)
				c=y-1;
			if(d==3)
				b=x-1;
			if(f[b][c]>0)
			{
				x=b;
				y=c;
			}
			else
				d=(d+1)%4;
			if(f[x][y]==1)
			{
				//cout<<x<<" "<<y<<endl;
				s++;
				f[x][y]=2;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}