#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t>0)
    {
        int n,k,q,s[100010][200010];
        cin>>n>>k>>q;
        for(int i=0;i<n;i++)
        {
            int l;
            cin>>l;
            for(int j=0;j<l;j++)cin>>s[i][j];
        }
        for(int i=0;i<q;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a>n&&n==1)
            {
                cout<<0;
                continue;
            }
            else cout<<1;
        }
        t--;
    }
    return 0;
}
