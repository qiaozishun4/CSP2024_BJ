#include<bits/stdc++.h>
using namespace std;
int a[1005][2005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int n,k,q;
    cin>>n>>k>>q;
    for(int i = 1; i<=n; i++)
    {
        cin>>a[i][0];
        for(int j = 1; j<=a[i][0]; j++)
        {
            cin>>a[i][j];
        }
    }
    int flag=0;
    while(q--)
    {
        int r,c;
        cin>>r>>c;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=a[i][0]; j++)
            {
                if(a[i][j]==c)
                {
                    flag=1;
                }
            }
        }
        if(flag) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}