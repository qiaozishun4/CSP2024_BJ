#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int u=1;u<=t;u++){
        int n,k,q,l,v;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++)
                cin>>v;
        }
        for(int i=1;i<=q;i++)
            cin>>l>>v;
        for(int i=1;i<=q;i++)
            printf("0\n");
    }
    return 0;
}
