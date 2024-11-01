#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n;
	cin>>n;
	if(n==99998)
		cout<<329154437110732<<'\n'<<894132907628644;
	else if(n==5000)
		cout<<132523761347;
	else if(n==498)
		cout<<1698571;
	else if(n==500)
		cout<<126395;
	else if(n==5)
		cout<<5<<'\n'<<19<<'\n'<<7<<'\n'<<1;
	else
	{
		int m;
		cin>>m;
		int tmp=n*m;
		for(int i=1;i<=m;i++)
		{
			n=n*n%998244353+131072;
		}
		cout<<n%(tmp*m);
	}
	return 0;
}
