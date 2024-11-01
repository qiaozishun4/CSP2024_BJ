#include<bits/stdc++.h>
using namespace std;
int s[1005][2005];
int h[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    int n,k,q;
    while(t--)
    {
        memset(h,0,sizeof(h));
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>len;
            for(int j=1;j<=len;j++)
            {
                cin>>s[i][j];
                h[s[i][j]]++;
            }
        }
        int r,c;
        while(q--)
        {
            cin>>r>>c;
            if(h[c]>=1)        
            {
                cout<<1<<'\n';
            }
            else 
            {
                cout<<0<<'\n';
            }
        }
    }
    return 0;
}
