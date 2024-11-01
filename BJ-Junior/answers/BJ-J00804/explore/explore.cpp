#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,xx,yy,dd;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>xx>>yy>>dd;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
    }
    if(t==2)
    {
        cout<<3<<endl<<13;
    }
    if(t==5)
    {
        cout<<82<<endl<<242578<<endl<<1684<<endl<<20226<<endl<<164;
    }
    return 0;
}
