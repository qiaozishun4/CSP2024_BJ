#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10,inf=1e9;
vector<int> v[N];
set<int> b[M];
int n,k,q;
bool dfs(int r,int c,int ned,int last)
{
	if(r<0)
	{
		return c==ned;
	}
	for(auto i:b[ned])
	{
		if(i==last) continue;
		int idx=0;
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j]==ned)
			{
				idx=j;
				for(int l=1;l<k&&l+idx<v[i].size();l++)
				{
					if(dfs(r-1,c,v[i][l+idx],i))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
		for(int i=0;i<N;i++)
		{
			v[i].clear();
		}
		for(int i=0;i<M;i++)
		{
			b[i].clear();
		}
        cin>>n>>k>>q;
        for(int i=1,x;i<=n;i++)
        {
            cin>>x;
            for(int j=1;j<=x;j++)
            {
				int a;
				cin>>a;
				b[a].insert(i);
				v[i].push_back(a);
            }
        }
		while(q--)
		{
			int r,c;
			cin>>r>>c;
			if(b[c].size()==0)
			{
				cout<<"0\n";
				continue;
			}
			if(r==1)
			{
				bool flag=0;
				if(b[1].size()<b[c].size())
				{
				for(auto i:b[1])
				{
					int check=-inf;
					for(int j=0;j<v[i].size();j++)
					{
						if(c==1&&v[i][j]==1&&j-check+1<=k)
						{
							flag=1;
							break;
						}
						if(v[i][j]==1)
						{
							check=j;
						}
						else if(v[i][j]==c&&j-check+1<=k)
						{
							flag=1;
							break;
						}
					}
					if(flag) break;
				}
				}
				else
				{
				for(auto i:b[c])
				{
					int check=-inf;
					for(int j=0;j<v[i].size();j++)
					{
						if(c==1&&v[i][j]==1&&j-check+1<=k)
						{
							flag=1;
							break;
						}
						if(v[i][j]==1)
						{
							check=j;
						}
						else if(v[i][j]==c&&j-check+1<=k)
						{
							flag=1;
							break;
						}
					}
					if(flag) break;
				}
				}
				cout<<flag<<'\n';
			}
			else
			{
				cout<<dfs(r-1,c,1,-1)<<'\n';
			}
		}
    }
    return 0;
}