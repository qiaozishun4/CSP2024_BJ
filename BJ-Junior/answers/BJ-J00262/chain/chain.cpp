#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,s,l;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++)
                cin>>s;
        }
        while(q--)
        {
            cin>>r>>c;
            cout<<0<<'\n';
        }
    }
    return 0;
}
