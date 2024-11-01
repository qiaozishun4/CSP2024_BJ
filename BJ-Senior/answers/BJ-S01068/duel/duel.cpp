#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long a[N];
int main()
{
	freopra("duel.in","r",stdin);
	freopra("duel.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]>a[j]&&a[i]!=true&&a[i]!=false&&a[j]!=false)
			{
				a[j]=false;
				a[i]=true;
			}
			else if(a[i]<=a[j]&&a[i]!=true&&a[j]!=false&&a[i]!=false)
			{
				a[i]=true;
			}
			else if(a[j]<=a[i]&&a[j]!=true&&a[j]!=false&&a[i]!=false)
			{
				a[j]=true;
			}
			else if(a[j]>a[i]&&a[j]!=true&&a[j]!=false&&a[i]!=false)
			{
				a[j]=true;
				a[i]=false;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			cnt++;
		}
	}
	int m=n-cnt;
	cout<<m;
	return 0;
}
