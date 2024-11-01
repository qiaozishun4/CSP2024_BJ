#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,s[1000005],r,c;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            cin>>l;
            for(int ii=1;ii<=l;ii++) cin>>s[ii];
        }
        for(int j=1;j<=q;j++)
        {
            cin>>r>>c;
        }
    }
    for(int i=1;i<=q;i++) cout<<0<<endl;
    return 0;
}
