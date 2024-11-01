#include <bits/stdc++.h>
using namespace std;
char x[1010][1010];
bool a[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x0,y0,d0;
        int ans=1;
        cin>>x0>>y0>>d0;
        int x1=x0,y1=y0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>x[i][j];
                a[i][j]=0;
            }
        }
        a[x0][y0]=1;
        while(k--)
        {
            if(d0==0) y1+=1;
            else if(d0==1) x1+=1;
            else if(d0==2) y1-=1;
            else x1-=1;
            if(1<=x1<=n && 1<=y1<=m && x[x1][y1]=='.')
            {
                x0=x1;
                y0=y1;
                if(a[x0][y0]==0)
                {
                    ans++;
                    a[x0][y0]=1;
                }
            }
            else
            {
                x1=x0;
                y1=y0;
                d0=(d0+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}