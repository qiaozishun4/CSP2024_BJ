#include<iostream>
#include<vector>
#define nu first
#define sv second
using namespace std;
int T,n,k,q,dp[105][200005],a[200005];
vector<pair<int,int>> p[200005];
bool srch(int f,int aim,int deep,int srv)
{
    if(f==aim and deep==0) return 1;
    else if(deep<=0) return 0;
    for(auto i:p[f])
    {
        if(srch(i.nu,aim,deep-1,i.sv) and i.sv!=srv) return 1;
    }
    return 0;
}
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
            int l;
            cin>>l;
            for(int j=1;j<=l;j++) cin>>a[j];
            for(int j=1;j<=l-k+1;j++)
            {
                for(int t=j+1;t<=j+k-1;t++)
                    p[a[j]].push_back({a[t],i});
            }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            cout<<srch(1,c,r,0)<<endl;
        }
    }
    return 0;
}
