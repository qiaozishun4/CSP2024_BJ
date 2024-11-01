#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],c[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],c[a[i]]++;
	sort(a+1,a+1+n);
	int j=a[1],ans=n;
	for(int i=a[1]+1;i<=a[n];)
	{
		while(c[i]==0&&i<=a[n]) i++;
		if(c[i]>=c[j]) 
		{
			int x=c[i]-c[j];
			ans-=c[j],j++;
			while(x&&j<i)
			{
				if(c[j]<=x)
				{
					x-=c[j];
					ans-=c[j];
				}
				else 
				{
					ans-=x,c[j]-=x;
					x=0;
					break;
				}
				j++;
			}
			i++;
		}
		else
		{
			ans-=c[i];
			c[j]-=c[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
