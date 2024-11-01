#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for (int i=0;i<(1<<n);i++)
		{
			int sum=0;
			for (int j=2;j<=n;j++)
				for (int k=j-1;k>=1;k--)
					if ((i>>(j-1)&1)==((i>>(k-1))&1))
						sum+=a[j]*(a[j]==a[k]);
			ans=max(ans,sum);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
