#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
char a[1005][1005];
int b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        for(int i=1;i<1005;i++)
        {
            for(int j=1;j<1005;j++)
            {
                b[i][j]=0;
                a[i][j]='0';
            }
        }
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        b[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        int x1,y1,d1;
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                x1=x;
                y1=y+1;
            }
            else if(d==1)
            {
                x1=x+1;
                y1=y;
            }
            else if(d==2)
            {
                x1=x;
                y1=y-1;
            }
            else if(d==3)
            {
                x1=x-1;
                y1=y;
            }


            if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&a[x1][y1]!='x')
            {
                x=x1;
                y=y1;
                b[x][y]=1;

            }
            else
            {
                d1=(d+1)%4;
                d=d1;

            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[i][j]==1)
                {
                    ans++;

                }
            }
        }
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
