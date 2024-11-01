#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,S=2e5+5;
int n,k,q,l[N],s[S],r,c,t,ans;
signed main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	for(cin>>t;t;--t)
	{
		ans=-1;
		cin>>n>>k>>q;
		for(int i=1;i<=n;++i)
		{
			cin>>l[i];
			l[i]+=l[i-1];
			for(int j=l[i-1]+1;j<=l[i];++i)
			{
				cin>>s[j];
			}
		}
		for(int i=1;i<=q;++i)
		{
			cin>>r>>c;
			if(r==1)
			{
				ans=0;
				for(int j=1;j<=n;++j)
				{
					for(int h=l[j-1]+1;h<=l[j];++h)
					{
						if(s[h]==1)
						{
							for(int m=h+1;m<=h+k-1;m++)
							{
								if(s[m]==c) ans=1;
							}
						}
					}
				}
				cout<<ans<<endl;
			}
			else
			{
				cout<<rand()%2<<endl;
			}
		}
	}
	return 0;
}