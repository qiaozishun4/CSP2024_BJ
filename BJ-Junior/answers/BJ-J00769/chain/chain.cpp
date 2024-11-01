#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+5;
vector<int>v[N];
int t,n,k,q,l,x,maxr,r[N],c[N];
bool ans[N<<1];
signed main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(cin>>t;t;t--)
	{
		memset(ans,false,sizeof ans);
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
			cin>>l;
			for(int j=1;j<=l;j++)
			{
				cin>>x;
				v[i].push_back(x);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				if(v[i][j]==1)
				{
					for(int m=j+1;m<j+k;m++)
					{
						ans[v[i][m]]=true;
					}
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>r[i]>>c[i];
			cout<<ans[c[i]]<<"\n";
		}
	}
	exit(0);
}