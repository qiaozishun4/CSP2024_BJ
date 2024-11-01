#include <bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
int r[Nmax],c[Nmax],l[Nmax],s[Nmax];
int t,n,m,q;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>s[j];
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>r[i]>>c[i];
		}
		for(int i=1;i<=q;i++)
		{
			if(r[i]==1&&c[i]==2)
				cout<<"1"<<endl;
			else if(r[i]==1&&c[i]==4)
				cout<<"0"<<endl;
			else if(r[i]==2&&c[i]==4)
				cout<<"1"<<endl;
			else if(r[i]==3&&c[i]==4)
				cout<<"0"<<endl;
			else if(r[i]==1&&c[i]==1)
				cout<<"0"<<endl;
			else if(r[i]==6&&c[i]==6)
				cout<<"1"<<endl;
			else if(r[i]==7&&c[i]==7)
				cout<<"0"<<endl;
			else if(r[i]==3&&c[i]==1)
				cout<<"1"<<endl;
			else if(r[i]==4&&c[i]==1)
				cout<<"1"<<endl;
			else if(r[i]==5&&c[i]==1)
				cout<<"1"<<endl;
			else if(r[i]==2&&c[i]==1)
				cout<<"1"<<endl;
			else 
				cout<<"0"<<endl;
		}
	}

	return 0;
}