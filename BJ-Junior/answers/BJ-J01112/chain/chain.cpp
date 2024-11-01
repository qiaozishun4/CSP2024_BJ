#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T,n,k,q,x,y;
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            for(int j=1;j<=x;j++)
            {
                cin>>y;
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>x>>y;
            cout<<((x+y)%k==0)<<endl;
        }
    }
    return 0;
}
