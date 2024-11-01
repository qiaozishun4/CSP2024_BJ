#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l[10005],r,c;
int a[1005][10005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>a[i][j];
            }
        }
        while(q--)
        {
            cin>>r>>c;
            bool f=1;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=l[i];j++)
                {
                    if(a[i][j]==c)
                    {
                        for(int o=j-1;o>=j-k+1;o--)
                        {
                            if(o>=0&&a[i][o]==1 &&f==1)
                            {
                                cout<<1<<"\n";
                                f=0;
                            }
                            if(f==0)
                            {
                                break;
                            }
                        }
                        if(!f)
                        {
                            break;
                        }
                    }
                    if(!f)
                    {
                        break;
                    }
                }
                if(!f)
                {
                    break;
                }
            }
            if(f)
            {
                cout<<0<<"\n";
            }
        }
    }
    return 0;
}
