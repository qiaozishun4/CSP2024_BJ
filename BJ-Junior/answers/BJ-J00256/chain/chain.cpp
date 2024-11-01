#include<bits/stdc++.h>
using namespace std;
long long l[2010],s[2010][2010],r[2010],c[2010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,k,q;
        cin>>n>>k>>q;
        for(long long i=1;i<=n;i++)
        {
            cin>>l[i];
            for(long long j=1;j<=l[i];j++)
            {
                cin>>s[i][j];
            }
        }
        for(long long i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
        }
        for(long long i=1;i<=q;i++)
        {
            if(r[i]==1)
            {
                long long d=0,m,u=0;
                for(long long i1=1;i1<=n;i1++)
                {
                    for(long long j=1;j<=l[i1];j++)
                    {
                        if(s[i1][j]==1)
                        {
                            m=j;
                            d=1;
                        }
                        if(d==1 && j-m+1<=k && s[i1][j]==c[i])
                        {
                            cout<<1<<endl;
                            u=1;
                            break;
                        }
                    }
                    if(u==1) break;
                }
                if(u==0) cout<<0<<endl;
            }
        }
    }
    return 0;
}
