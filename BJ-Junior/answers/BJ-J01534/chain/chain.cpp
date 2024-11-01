#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            int l;
            cin>>l;
            for(int j=1;j>=l;j++)
            {
                int a;
                cin>>a;
            }
        }
        for(int i=1;i<=q;i++)
        {
            int a,b;
            cin>>a>>b;
            if(b==a&&a%2==1)cout<<0<<endl;
            else if(b%a==0)cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
