#include <bits/stdc++.h>
using namespace std;
int f()
{
    int n,m,k,d,x,y,i,sum=0,j;
    char s;
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    bool a[n+1][m+1];
    bool fl[n+1][m+1];
    fl[--x][--y]=true;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>s;
            if(s=='x')a[i][j]=false;
            else if(s=='.')a[i][j]=true;
            fl[i][j]=false;
        }
    }
    for(i=1;i<=k;i++)
    {
        if(d==0)
        {
            if(a[x][y+1]==false||y+1>=m)d=(d+1)%4;
            else if(a[x][y+1])
            {
                y+=1;
                fl[x][y]=true;
                continue;
            }
        }
        else if(d==1)
        {
            if(a[x+1][y]==false||x+1>=n)d=(d+1)%4;
            else if(a[x+1][y])
            {
                x+=1;
                fl[x][y]=true;
                continue;
            }

        }
        else if(d==2)
        {
            if(a[x][y-1]==false||y-1<0)d=(d+1)%4;
            else if(a[x][y-1])
            {
                y-=1;
                fl[x][y]=true;
                continue;
            }
        }
        else if(d==3)
        {
            if(a[x-1][y]==false||x-1<0)d=(d+1)%4;
            else if(a[x-1][y])
            {
                x-=1;
                fl[x][y]=true;
                continue;
            }
        }      
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(fl[i][j])sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        f();
    }
    return 0;
}