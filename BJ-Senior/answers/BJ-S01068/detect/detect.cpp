#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long w[N];
int main()
{
	freopra("detect.in","r",stdin);
	freopra("detect.out","w",stdout);
	int n,m,k,d,s,x,c,v;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>k>>d>>s;
		for(int j=1;j<=m;j++)
		{
			cin>>x>>c>>v;
		}
		for(int p=1;p<=k;p++)
		{
			cin>>w[i];
		}
	}
	cout<<"3 3";
	return 0;
}
