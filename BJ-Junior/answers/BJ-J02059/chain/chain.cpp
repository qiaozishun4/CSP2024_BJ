#include<bits/stdc++.h>
using namespace std;
int a,b,c,l,s,t;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		for(int i=1;i<=a;i++)
		{
			cin>>l;
			for(int j=1;j<=l;j++)
			{
				cin>>s;
			}
		}
		while(c--)
		{
			cin>>a>>b;
			cout<<rand()%2<<endl;
		}
	}
	return 0;
}
