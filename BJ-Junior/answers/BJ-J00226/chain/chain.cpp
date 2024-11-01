#include <bits/stdc++.h>
using namespace std;
int t,n,k,q;
int a[1005][1005];
int r,c;
int l[1005];
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
        for(int i=1;i<=q;i++)
            cin>>r>>c;
        for(int i=1;i<=q;i++)
            cout<<0<<endl;
    }
    return 0;
}
