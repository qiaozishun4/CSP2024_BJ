#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k,q;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++)
		{
			cin>>l[j];
			for(int k=1;k<=l[j];k++)
			{
				cin>>s[k];
			}
		}
		for(int j=1;j<=q;j++)
		{
			cin>>r[j]>>c[j];
		}
		for(int j=1;j<=q;j++)
		{
			for(int k=1;k<=r[j];k++)
			{
				if(c[k]==s[k])
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
	}
	return 0;
}