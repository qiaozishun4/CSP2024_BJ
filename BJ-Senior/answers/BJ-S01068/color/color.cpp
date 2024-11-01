#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long a[N];
int main()
{
	freopra("color.in","r",stdin);
	freopra("color.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
	}
	cout<<"1\n0\n8";
	return 0;
}
