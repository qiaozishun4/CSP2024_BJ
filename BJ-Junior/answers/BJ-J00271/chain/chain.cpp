#include<bits/stdc++.h>
using namespace std;
int n,m,k,q,T,x,y,d,a[2005][2005];
//person ,S[person] ,limitl ,jielong , lastletter , firstperson , firstletter
bool dfs(int n,int k,int r,int c,int p,int f)
{
    bool ans[200005];
    int cnt=0;
    if(r==1)
    {
        for(int j=1;j<=n&&a[p][j]==f;j++)
        {
            for(int u=1;u<=k;u++)
            {
                if(a[p][j+u]==c) return true;
            }
        }
        return false;
    }
    else
    {
        for(int i=1;i<=n&&i!=p;i++)
        {
            for(int j=1;j<=n&&a[i][j]==f;j++)
            {
                for(int u=1;u<=k;u++)
                {
                    ans[++cnt]=dfs(n,k,r-1,c,i,a[i][j+u]);
                }
            }
        }
        for(int i=1;i<=cnt;i++) if(ans[i]) return true;
        return false;
    }
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
           for(int j=1;j<=l;j++)
           {
               cin>>a[i][j];
           }
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            for(int i=1;i<=n;i++)
            {
                if(dfs(n,k,r,c,i,1))
                {
                    cout<<1<<endl;
                    break;
                }
            }
            cout<<0<<endl;
        }
    }
    return 0;
}
