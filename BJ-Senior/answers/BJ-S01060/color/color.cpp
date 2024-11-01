#include<bits/stdc++.h>
using namespace std;
namespace bruteforce
{
	constexpr int N=200000+5;
	int n;
	int a[N];
	void sol()
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		int ans=0;
		for(int i=0;i<((1<<n)-1);++i)
		{
			int cr=0;
			for(int j=1;j<=n;++j)
			{
				for(int k=j-1;k>0;--k)
				{
					if(((bool)(i&(1<<(j-1))))==((bool)(i&(1<<(k-1)))))
					{
						if(a[k]==a[j]) cr+=a[j];
						break;
					}
				}
			}
			ans=max(ans,cr);
		}
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		bruteforce::sol();
		
	}
	return 0;
}
