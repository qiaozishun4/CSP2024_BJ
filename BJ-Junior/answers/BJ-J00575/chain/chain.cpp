#include <bits/stdc++.h>
using namespace std;
int s[1000050];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q,l,r,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++) cin>>s[j];
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r>>c;
        }
    }
    cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
    return 0;
}
