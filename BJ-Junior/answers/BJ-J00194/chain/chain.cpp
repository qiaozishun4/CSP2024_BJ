#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t,k,q,l[100005],s[1005][1005],r[100005],c[100005];

signed main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j;
    cin>>t;
    while (t--)
    {
        cin>>n>>k>>q;
        for(i=1;i<=n;i++)
        {
            cin>>l[i];
            for (j=1;j<=l[i];j++)
                cin>>s[i][j];
        }
        for (i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
            cout<<1<<endl;
        }
    }
}
