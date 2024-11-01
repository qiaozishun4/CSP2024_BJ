#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		n*=2;
		for(int i=1;i<=n;i+=2)
		{
			cin>>a[i];
			a[i+1]=0;
		}
		long long cnt=0;
		for(int i=2;i<=n-1;i++)
		{
			int maxn=0;
			for(int j=1;j<=i;j++)
			{
				if(a[i-j]==a[i+j])
				{
					maxn=max(maxn,a[i-j]);
				}
			}
			cnt+=maxn;
		}
		cout<<cnt<<endl;
	}
	return 0;
}