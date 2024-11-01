#include<bits/stdc++.h>
using namespace std;
int a[100010];
int s[100010][100010];
int r[100010],c[100010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k,q;
        cin>>n>>k>>q;
        int maxn=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            for(int x=1;x<=a[j];x++)
            {
                cin>>s[j][x];
                maxn=max(maxn,s[j][x]);
            }
        }
        for(int y=1;j<=q;y++)
        {
            cin>>r[y]>>c[y];
            if(r[y]==1&&c[y]>=2)
            {
                cout<<1<<endl;
            }
            else if(r[y]==1&&c[y]<2)
            {
                cout<<0<<endl;
            }
            else if(c[y]>maxn)
            {
                cout<<0<<endl;
            }
        }
    }
    
    
    
    
    return 0;
}
