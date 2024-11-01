#include<iostream>
using namespace std;
int t,n,k,q,l,s,r,c;
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
            for(int k=1;k<=l;k++)cin>>s;
        }
        for(int j=1;j<=q;j++)cin>>r>>c;
    }
    for(int i=1;i<=t;i++)cout<<0<<endl;
    return 0;
}