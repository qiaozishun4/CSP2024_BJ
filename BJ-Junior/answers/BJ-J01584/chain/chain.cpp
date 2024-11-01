#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
        freopen("chain.out","w",stdout);

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,kk,q;
        int o[100005]={0};
        cin>>n>>kk>>q;
        int p[1005][1005];
        for(int j=0;j<n;j++)
        {
            int l;
            cin>>l;
            for(int k=0;k<l;k++)
            {
                int b;
                cin>>b;
                p[j][k]=b;
                o[j]++;
            }
        }
        for(int j=0;j<q;j++)
        {
            int l,b;
            cin>>l>>b;
            bool m=0,ks=0;
            for(int j=0;j<n;j++)
            {
                int y=0;
                for(int k=0;k<o[j];k++)
                {
                    if(p[j][k]==b&&ks==1&&y<kk)
                    {
                        m++;
                        y=0;
                        break;
                    }
                    if(p[j][k]==1)
                    {
                        y=0;
                        ks++;
                    }
y++;

                }
                ks=0;
            }
            cout<<m<<endl;
    }
    }
    return 0;
}
