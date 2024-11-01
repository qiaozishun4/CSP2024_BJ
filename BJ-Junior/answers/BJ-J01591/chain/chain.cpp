#include <bits/stdc++.h>
using namespace std;
int a[10010][10010];
int l[10010];
int r[10010];
int c[10010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            cin>>l[j];
            for(int k=1;k<=l[i];k++)
            {
                cin>>a[j][k];
            }
        }
        for(int j=1;j<=q;j++)
        {
            int tmp=-1;
            cin>>r[i]>>c[i];
            for(int k=1;k<=n;k++)
            {
                for(int u=1;u<=l[k];u++)
                {
                    if(a[k][u]=='1') tmp=u;
                    if(a[k][u]==c[i]&&tmp!=-1&&k>u-tmp)
                    {
                        tmp=-2;
                        cout<<"1"<<endl;
                        break;
                    }
                }
                if(tmp!=-2) cout<<"0"<<endl;
            }
        }
    }
    return 0;
}
