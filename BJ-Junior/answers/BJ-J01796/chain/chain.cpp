#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,vis[200005],r,c,s;
vector<long long>a[1005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                cin>>s;
                a[i].push_back(s);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                if(a[i][j]==1)
                {
                    for(int kk=j+1;kk<=a[i].size()&&kk<j+k;kk++)
                    {
                        vis[a[i][kk]] = 1;
                    }
                    break;
                }
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r>>c;
            if(vis[c]==1)
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
        for(int i=1;i<=n;i++)
        {
            a[i].clear();
        }
    }
    return 0;
}