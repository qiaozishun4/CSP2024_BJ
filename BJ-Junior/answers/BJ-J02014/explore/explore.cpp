#include <bits/stdc++.h>
using namespace std;
const int Nmax=1e4+7;
char a[Nmax][Nmax];
int n,m,t,k,x,y,d0;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(k==1)
				{
					if(d0==0&&a[x][y+1]=='.')
					{
						cout<<"1"<<endl;
						break;
					}
					else if(d0==1&&a[x+1][y]=='.')
					{
						cout<<"1"<<endl;
						break;
					}
					else if(d0==2&&a[x][y-1]=='.')
					{
						cout<<"1"<<endl;
						break;
					}
					else if(d0==3&&a[x][y-1]=='.')
					{
						cout<<"1"<<endl;
						break;
					}
					else 
					{
						cout<<"0"<<endl;
						break;
					}
				}
			}
			break;
		}
	}
	return 0;
}