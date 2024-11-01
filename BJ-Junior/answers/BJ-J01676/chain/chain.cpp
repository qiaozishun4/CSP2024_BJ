#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[200005],s[1005][1005],r[1005],c[1005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int flag=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
            if(r[i]==1)
            {
                for(int j=1;j<=n;j++)
                {
                    int flag1=0;
                    for(int k=1;k<=l[j];k++)
                    {
                        if(s[j][k]==1)
                        {
                            flag1=1;
                        }
                        if(flag==1&&s[j][k]==c[i])
                        {
                            flag=1;
                        }
                    }
                }

            }
        }
        if(flag==1)
        {
            cout<<1<<'\n';
        }
        else
        {
            cout<<0<<'\n';
        }
    }
    return 0;
}
