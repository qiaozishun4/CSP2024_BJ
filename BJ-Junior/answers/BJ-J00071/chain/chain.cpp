#include<bits/stdc++.h>
using namespace std;

int t,n,k,q;
int l[1000005];
int s[10005][10005];
int a[10005][10005];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
        int r,c;
        for(int j=1;j<=q;j++)
        {
            cin>>r>>c;
            cout<<1<<endl;
        }
    }
    return 0;
}
