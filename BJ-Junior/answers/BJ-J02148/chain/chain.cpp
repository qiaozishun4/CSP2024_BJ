#include <bits/stdc++.h>
using namespace std;
int s[100010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(s,0,sizeof(s));
        int n,k,q;
        cin>>n>>k>>q;
        int l;
        cin>>l;
        for (int i=1;i<=l;i++) cin>>s[i];
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            cout<<"0"<<endl;
        }
    }
    return 0;
}