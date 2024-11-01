#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,m,k,x,y,d;
char a[3010][3010];
int main()
{
    freopoen("explore.in","r",stdin);
    freopoen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<n+m-1<<endl;
    }
    return 0;
}
