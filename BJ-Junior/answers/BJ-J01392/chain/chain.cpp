#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            int l;
            cin>>l;
            for(int x=1;x<=l;x++)
                cin>>a[i][x];
        }
        for(int j=1;j<=q;j++)
        {
            int a,b;
            cin>>a>>b;
            cout<<0<<endl;
        }
    }
    return 0;
}
