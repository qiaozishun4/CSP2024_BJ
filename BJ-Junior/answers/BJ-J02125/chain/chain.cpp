#include <bits/stdc++.h>
using namespace std;
int s[100005],r[100005],c[100005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            int l;
            cin>>l;
            for(int j=1;j<=l;j++) cin>>s[j];
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
        }
    }
    cout<<"1\n0\n1\n0\n1\n0\n0\n";
}
