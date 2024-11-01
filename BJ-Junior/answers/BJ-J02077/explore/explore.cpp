#include<bits/stdc++.h>
using namespace std;
char a[1002][1002];
int a1[1002][1002];
int sum[6];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    memset(a1,0,sizeof(a1));
    int t;
    cin>>t;
    int n,m,k,x,y,d;
    for(int i=1;i<=t;i++)
    {
        sum[i]=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        a1[x][y]=1;
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=m;l++)
            {
                cin>>a[i][j];
            }
        }
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                if((a[x][y+1]!='x')&&(y+1<=m))
                {
                    y=y+1;
                    a1[x][y]=1;

                }
                else
                {
                    d++;

                }
                continue;
            }
            else if(d==1)
            {
                if((a[x+1][y]!='x')&&(x+1<=n))
                {
                    x=x+1;
                    a1[x][y]=1;

                }
                else
                {
                    d++;

                }
                continue;
            }
            else if(d==2)
            {
                if(a[x][y-1]!='x')
                {
                    if(y-1!=0)
                    {
                        y=y-1;
                        a1[x][y]=1;
                    }
                    else
                    {
                        d++;
                    }

                }
                else
                {
                    d++;
                }
                continue;
            }
            else if(d==3)
            {
                if((a[x-1][y]!='x')&&(1<=x-1))
                {
                    x=x-1;
                    a1[x][y]=1;
                }
                else
                {
                    d=0;
                }
                continue;
            }
        }
    }
    for(int i=1;i<=t;i++)
    {
        cout<<sum[i]<<endl;
    }
    return 0;
}
