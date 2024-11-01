#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N][N];
int c,r,las[N];
int T,n,K,q,l,x;
bool dfs(int i,int j,int r)
{
    if(r==1)
    {
        for(int k=j-K+1;k<=j-1;k++)
        {
            if(a[i][k]==1) return 1;
        }
        return 0;
    }
    for(int z=1;z<=n;z++)
    {
        if(z==i) continue;
        for(int k=j-1;k>=j-K+1;k--)
        {
            for(int m=1;m<=a[z][0];m++)
            {
                if(a[i][k]==a[z][m]) dfs(z,m,r-1);
            }
        }
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
        cin>>n>>K>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            a[i][0]=l;
            for(int j=1;j<=l;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r>>c;
            if(r==1)
            {
                bool flag=false;
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=a[i][0];j++)
                    {
                        if(a[i][j]!=c) continue;
                        for(int k=j-1;k>=1;k--)
                        {
                            if(a[i][k]==1)
                            {
                                int m=j-k+1;
                                if(m<=K)
                                {
                                    cout<<1<<endl;
                                    flag=true;
                                }
                                break;
                            }
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
                if(!flag) cout<<0<<endl;
            }
            else if(r<=5)
            {
                bool b=false;
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=a[i][0];j++)
                    {
                        if(a[i][j]==c) b=max(b,dfs(i,j,r));
                    }
                }
                if(b) cout<<1<<endl;
                else cout<<0<<endl;
            }
        }
    }
    return 0;
}
