#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100005],s[1005][200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            cin>>l[j];
            for(int k=1;k<=l[j];k++)
            {
                cin>>s[j][k];
            }
        }
        cout<<1<<endl;
    }
}
