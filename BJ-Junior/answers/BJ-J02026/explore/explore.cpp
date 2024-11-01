#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool b[1001][1001]={0};
int doo()
{
    int n,m,k;
    int x,y,d;
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    
    for(int i=1;i<=k;i++)
    {
        b[x][y]=1;
        if(d==0)
        {
            if(y+1<=m)
            {
                if(a[x][y+1]=='.'){y++;}
                else d=(d+1)%4;
            }
            else d=(d+1)%4;
        }
        if(d==1)
        {
            if(x+1<=n)
            {
                if(a[x+1][y]=='.'){x++;}
                else d=(d+1)%4;
            }
            else d=(d+1)%4;
        }
        if(d==2)
        {
            if(y-1>=1)
            {
                if(a[x][y-1]=='.'){y--;}
                else d=(d+1)%4;
            }
            else d=(d+1)%4;
        }
        if(d==3)
        {
            if(x-1>=1)
            {
                if(a[x-1][y]=='.')x--;
                else d=(d+1)%4;
            }
            else d=(d+1)%4;
        }
    }
    int t=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            t+=b[i][j];
        }
    }
    memset(b,0,sizeof(b));
    return t;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cout<<doo()<<endl;
    }
    return 0;
}