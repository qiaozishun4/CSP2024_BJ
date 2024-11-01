#include <bits/stdc++.h>
#include <iostream>
int maap[1001][1001]={0};
int vision[1001][1001]={0};


int clean(int n,int m)
{
    for (long i=1;i<=n;i++)
    {
        for (long j=1;j<=m;j++)
        {
            maap[i][j]=0;
            vision[i][j]=0;
        }
    }
    return 0;
}
bool coll(int x,int y,int d,int n,int m)
{
    int xx,yy;
    if (d==0)
    {
        xx=x;
        yy=y+1;
    }
    if (d==1)
    {
        xx=x+1;
        yy=y;
    }
    if (d==2)
    {
        xx=x;
        yy=y-1;
    }
    if (d==3)
    {
        xx=x-1;
        yy=y;
    }
    if (xx<=n&&xx>=1&&yy<=m&&yy>=1)
    {
        if (maap[xx][yy]==2)
        {

            return true;
        }
    }
    return false;
}
int dps(int x,int y,int d,int n,int m,int k)
{
    while (k>0)
    {
        if (coll(x,y,d,n,m))
        {
            if (d==0)
            {
                vision[x][y+1]=1;
                k--;
                dps(x,y+1,d,n,m,k);
            }
            if (d==1)
            {
                vision[x+1][y]=1;
                k--;
                dps(x+1,y,d,n,m,k);
            }
            if (d==2)
            {
                vision[x][y-1]=1;
                k--;
                dps(x,y-1,d,n,m,k);
            }
            if (d==3)
            {
                vision[x-1][y]=1;
                k--;
                dps(x-1,y,d,n,m,k);
            }
        }
        else{
            d=(d+1)%4;
            k--;
            dps(x,y,d,n,m,k);
        }
    }
    return 0;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    std::cin>>t;
    long n,m,k,xa,ya,da,ans=0;
    char a;
    for (int i=0;i<t;i++)
    {
        std::cin>>n>>m>>k;
        std::cin>>xa>>ya>>da;
        vision[xa][ya]=1;
        for (long j=1;j<=n;j++)
        {
            for (long p=1;p<=m;p++)
            {
                    std::cin>>a;
                    if (a=='.')
                    {

                        maap[j][p]=2;
                    }
                    if (a=='x')
                    {
                        maap[j][p]=1;

                    }
            }
        }
        dps(xa,ya,da,n,m,k);

        for (long j=1;j<=n;j++)
        {
            for (long p=1;p<=m;p++)
            {
                if (vision[j][p]==1)
                {
                    ans++;
                }
            }
        }
        std::cout<<ans<<std::endl;

        clean(n,m);
        ans=0;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
