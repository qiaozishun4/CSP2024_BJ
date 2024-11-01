#include <bits/stdc++.h>
using namespace std;
string f[100000];
bool r(int b,int c,int d)
{
	return 1;
}
int main()
{
	//freopen("chain.in","r",stdin);
	//freopen("chain.out","w",stdout);
	int n,k,q,l;
	string a;
	cin>>n>>k>>q>>b>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>l;
		for(int j=1;j<=l;j++)
		{
			cin>>a;
			f[i]+=a;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int t=0;
		cin>>b>>c;
		for(int i=1;i<=n;i++)
			if(r(b,c,i))
			{
				t=1;
				break;
			}
		if(t)
			cout<<1;
		else
			cout<<0;
	}
	return 0;
}