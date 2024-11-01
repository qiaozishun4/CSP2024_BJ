#include<bits/stdc++.h>
using namespace std;
long long T,n,k,q,a[1010100];
bool f[201010];
vector<int> v[1010100];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        	for(int j=1;j<=a[i];j++)
        	{
        		int x;
        		cin>>x;
        		v[i].push_back(x);
        	}
		}
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			int valu=0;
			for(int j=0;j<a[i];j++)
			{
				if(valu) f[v[i][j]]=1;
				if(valu>0) valu--;
				if(v[i][j]==1)
				{
					valu=k-1;
				}
			}
		}
		while(q--)
		{
			int j,u;
			cin>>j>>u;
			cout<<f[u]<<endl;
		}
    }
    return 0;
}
