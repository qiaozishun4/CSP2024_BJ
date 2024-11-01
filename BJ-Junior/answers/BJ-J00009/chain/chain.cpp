#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		vector<int> v[100050];
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			int l;
			cin>>l;
			for(int j=1;j<=l;j++)
			{
				int x;
				cin>>x;
				v[i].push_back(x);
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			if(x==1)
			{
				int flag=0;
				for(int i=1;i<=n;i++)
				{
					for(int j=0;j<v[i].size();j++)
					{
						if(v[i][j]==1)
						{
							for(int p=2;p<=k;p++)
							{
								for(int o=j;o<=j+p-1&&o<v[i].size();o++)
								{
									if(v[i][o]==y)
									{
										flag=1;
										cout<<1<<'\n';
										break;
									}
								}
								if(flag) break;
							}
							if(flag) break;
						}
						if(flag) break;
					}
					if(flag) break;
				}
				if(!flag) cout<<0<<'\n';
			}
			else cout<<0<<'\n';
		}
	}
	return 0;
}
