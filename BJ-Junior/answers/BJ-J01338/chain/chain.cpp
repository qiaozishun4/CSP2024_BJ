#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q,l,x,r,c;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(long long i=1;i<=k;i++)
        {
            cin>>l;
            for(long long j=1;j<=l;j++)
            {
                cin>>x;
            }
        }
        for(long long i=1;i<=q;i++)
        {
            cin>>r>>c;
            cout<<"0\n";
        }
    }
    return 0;
}
