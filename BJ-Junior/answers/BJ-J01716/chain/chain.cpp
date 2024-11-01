
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,k,m,cnt;
vector<int>g[maxn];
int r,c;
bool dp[maxn*2];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cnt=1;
        cin>>n>>k>>m;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            int l;
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                int x;
                cin>>x;
                g[i].push_back(x);
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<g[i].size();j++)
                if(g[i][j]==1)
                    for(int l=1;l<k && l+j<g[i].size();l++)
                        dp[g[i][j+l]]=true;
        for(int i=1;i<=m;i++)
        {
            cin>>r>>c;
            cout<<dp[c]<<"\n";
        }
    }
    return 0;
}
