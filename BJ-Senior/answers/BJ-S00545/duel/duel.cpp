#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int cnt=0,n,a[N],h[N],sum[N],num=1;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	h[num]++;//a[1]
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			h[num]++;
		}
		else
		{
			num++;
			h[num]++;
		}
	}
	for(int i=1;i<=num;i++)
	{
		sum[i]=sum[i-1]+h[i-1];
	}
	for(int i=1;i<=num;i++)
	{
		sum[i]-=cnt;
		if(h[i]>=sum[i])
		{
			cnt+=sum[i];
		}
		else
		{
			cnt+=h[i];
		}
	}
	cout<<n-cnt;
	return 0;
}
