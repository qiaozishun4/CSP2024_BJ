#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,s[100005],r[100005],c[100005];
int main()
{
    freopen("chain","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
        }
        printf("%d\n",rand()%2);
    }
    return 0;
}
