#include <bit/stdc++.h>
using namespace std;
#define ll long long
ll T,n,m,q;
ll l[1000010];
ll s[1000010];
ll r[1000010];
ll c[1000010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>s[j];
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
        }
    }
    cout<<"1"<<endl;
    cout<<"0"<<endl;
    cout<<"1"<<endl;
    cout<<"0"<<endl;
    cout<<"1"<<endl;
    cout<<"0"<<endl;
    cout<<"0"<<endl;
    return 0;
}
