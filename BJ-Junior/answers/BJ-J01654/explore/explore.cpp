#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x0,y00,d0;
char a[1005][1005];
int b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    int tt=t-1;
    while(t--)
    {
        int ans=1;
        memset(a,' ',sizeof(a));
        memset(b,0,sizeof(b));
        cin>>n>>m>>k;
        cin>>x0>>y00>>d0;
        b[x0][y00]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        while(k--)
        {
            int xx=0,yy=0;
            if(d0==0)
            {
                xx=x0;
                yy=y00+1;
            }
            if(d0==1)
            {
                xx=x0+1;
                yy=y00;
            }
            if(d0==2)
            {
                xx=x0;
                yy=y00-1;
            }
            if(d0==3)
            {
                xx=x0-1;
                yy=y00;
            }
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.')
            {
                //cout<<xx<<" "<<yy<<endl;
                //ans++;
                if(b[xx][yy]!=1)
                {
                    b[xx][yy]=1;
                    ans++;
                }
                x0=xx;
                y00=yy;
            }
            else
            {
                d0=(d0+1)%4;
            }

        }
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
