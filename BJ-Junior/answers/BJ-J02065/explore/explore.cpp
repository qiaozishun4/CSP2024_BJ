#include<bits/stdc++.h>

using namespace std;

int t,d,m,n,k,x,y;
long long sum;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        sum=1;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int b=1;b<=n;b++)
        {
            for(int c=1;c<=m;c++)
            {
                cin>>a[b][c];
            }
        }
        if(d==0)
        {
            if(a[x][y+1]=='.')
            {
                y=y+1;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        else if(d==1)
        {

            if(a[x+1][y]=='.')
            {
                x=x+1;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        else if(d==2)
        {
            if(a[x][y-1]=='.')
            {
                y=y-1;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        else
        {
            if(a[x-1][y]=='.')
            {
                x=x-1;
            }
            else
            {
                d=(d+1)%4;
            }
        }

        for(int j=2;j<=k;j++)
        {
            if(d==0)
            {
                if(a[x][y+1]=='.')
                {
                    sum++;
                    y=y+1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==1)
            {

                if(a[x+1][y]=='.')
                {
                    sum++;
                    x=x+1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==2)
            {

                if(a[x][y-1]=='.')
                {
                    sum++;
                    y=y-1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else
            {
                if(a[x-1][y]=='.')
                {
                    sum++;
                    x=x-1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
