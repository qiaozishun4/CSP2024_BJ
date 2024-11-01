#include<bits/stdc++.h>
using namespace std;
int T,a[1005][2005],l[1005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int i,j,k;
	cin>>T;
	while(T--)
	{
		int n,m,q;
		cin>>n>>m>>q;
		for(i=1;i<=n;i++)
		{
			cin>>l[i];
			for(j=1;j<=l[i];j++)
				cin>>a[i][j];
		}
		while(q--)
		{
			int c,r;
			bool flag=false;
			cin>>c>>r;
			for(i=1;i<=n;i++)
				for(j=1;j<=l[i]-m+1;j++)
				{
					if(a[i][j]==1)
						for(k=j;k<=j+m-1;k++)
							if(a[i][k]==r)
							{
								flag=true;
								break;
							}
				}
			if(flag)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}