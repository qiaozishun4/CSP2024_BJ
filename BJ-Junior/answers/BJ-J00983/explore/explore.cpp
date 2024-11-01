#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int q=1;q<=T;q++)
    {
        int n,m,k,ans=0;
        cin>>n>>m>>k;
        int x0,y0,d;
        cin>>x0>>y0>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                b[i][j]=0;
            }
        }
        b[x0][y0]=1;
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(a[x0][y0+1]=='x' || y0+1>m)
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    y0++;
                    b[x0][y0]=1;
                }
            }
            else if(d==1)
            {
                if(a[x0+1][y0]=='x' || x0+1>n)
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    x0++;
                    b[x0][y0]=1;
                }
            }
            else if(d==2)
            {
                if(a[x0][y0-1]=='x' || y0-1<1)
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    y0--;
                    b[x0][y0]=1;
                }
            }
            else if(d==3)
            {
                if(a[x0-1][y0]=='x' || x0-1<1)
                {
                    d=(d+1)%4;
                    continue;
                }
                else
                {
                    x0--;
                    b[x0][y0]=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[i][j]==1)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
