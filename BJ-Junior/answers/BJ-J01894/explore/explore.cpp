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
    for(int l=1; l<=T; l++)
    {
        int n,m,k,x,y,d,ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1; i<=1000; i++)
        {
            for(int j=1; j<=1000; j++)
            {
                b[i][j]=0;
            }
        }
        b[x][y]=1;
        for(int i=1; i<=1000; i++)
        {
            for(int j=1; j<=1000; j++)
            {
                a[i][j]='0';
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1; i<=k; i++)
        {
            int ret=0;
            if(d==0)
            {
                if(y!=m&&a[x][y+1]!='x')
                {
                    b[x][y+1]++;
                    y=y+1;
                }
                else{
                    d=(d+1)%4;
                    ret++;
                }
            }
            if(d==1&&ret==0)
            {
                if(x!=n&&a[x+1][y]!='x')
                {
                    b[x+1][y]++;
                    x=x+1;
                }
                else{
                    d=(d+1)%4;
                    ret++;
                }
            }
            if(d==2&&ret==0)
            {
                if(y!=1&&a[x][y-1]!='x')
                {
                    b[x][y-1]++;
                    y=y-1;
                }
                else{
                    d=(d+1)%4;
                    ret++;
                }
            }
            if(d==3&&ret==0)
            {
                if(x!=1&&a[x-1][y]!='x')
                {
                    b[x-1][y]++;
                    x=x-1;
                }
                else{
                    d=(d+1)%4;
                    ret++;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                 if(b[i][j]!=0)
                 {
                     ans++;
                 }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}