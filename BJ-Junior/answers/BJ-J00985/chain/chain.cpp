#include <bits/stdc++.h>
using namespace std;
int a[1001][2001];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            a[i][0]=x;
            for(int j=1;j<=x;j++)cin>>a[i][j];
        }
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            bool f=0;
            for(int i=1;i<=n;i++)
            {
                if(f)break;
                if(a[i][0]<k)continue;
                for(int j=k;j<=a[i][0];j++)if(a[i][j]==c){f=1;break;}
            }
            if(f)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}