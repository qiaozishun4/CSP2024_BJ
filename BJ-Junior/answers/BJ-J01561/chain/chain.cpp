#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,a[1001][2001],r,c,l[1001];
bool g(int t,int v,int go)
{
    if(t==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==v) continue;
            for(int j=1;j<=l[i];j++)
            {
                if(a[i][j]==go)
                {
                    int h=min(k,j);
                    for(int len=1;len<h;len++)
                    {
                        if(a[i][j-len]==1) return 1;
                    }
                }
            }
        }
        return 0;
    }
    bool ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i==v) continue;
        for(int j=1;j<=l[i];j++)
        {
            if(a[i][j]==go)
            {
                int h=min(k,j);
                for(int len=1;len<h;len++) 
                {
                    ans|=g(t-1,i,a[i][j-len]);
                    if(ans) return 1;
                }
            }
        }
    }
    return ans;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++) cin>>a[i][j];
        }
        while(q--)
        {
            cin>>r>>c;
            cout<<g(r,0,c)<<"\n";
        }
    }
    return 0;
}