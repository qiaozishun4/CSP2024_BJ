#include<bits/stdc++.h>
using namespace std;
int a[1000][1000],b[1000],n,k,r,c,ans;
bool pop(int x,int y,int r)
{
	if(r==1)
	{
		for(int e=1;e<k;e++)
			if(c==a[x][y+e]) return true;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(i==x) i++;
			for(int j=0;j<b[i];j++)
				for(int e=1;e<k;e++)
					if(a[i][j]==a[x][y+e]&&pop(i,j,r-1)==true)
						return true;
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,q;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			for(int j=0;j<b[i];j++)
				cin>>a[i][j];
		}
		while(q--)
		{
			int flag=0;
			cin>>r>>c;
			for(int i=0;i<n&&flag==0;i++)
				for(int j=0;j<b[i]&&flag==0;j++)
				{
					if(a[i][j]==1)
						if(pop(i,j,r)==true)
						{
							cout<<1<<endl;
							flag=1;
						}
				}
			if(flag==0) cout<<0<<endl;
		}
	}
	return 0;
}		
