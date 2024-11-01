#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x0=0;
int d0=0;
int y2=0;
bool vis[1005][1005];
char mmap[1005][1005];
bool judge(int x,int y)
{
    if(x<1||x>n||y<1||y>m)
    {
        return false;
    }
    else if(mmap[x-1][y-1]=='x')
    {
        return false;
    }
    else
    {
        vis[x-1][y-1]=true;
        return true;
    }
}
void f()
{
    if(d0==0)
    {
        if(judge(x0,y2+1)==false)
        {
            d0=(d0+1)%4;
        }
        else{
            y2++;
        }
    }
    else if(d0==1)
    {
        if(judge(x0+1,y2)==false)
        {
            d0=(d0+1)%4;
        }
        else{
            x0++;
        }
    }
    else if(d0==2)
    {
        if(judge(x0,y2-1)==false)
        {
            d0=(d0+1)%4;
        }
        else{
            y2--;
        }
    }
    else if(d0==3)
    {
        if(judge(x0-1,y2)==false)
        {
            d0=(d0+1)%4;
        }
        else{
            x0--;
        }
    }
}
int numm()
{
    int ci=0;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=m-1;j++)
        {
            if(vis[i][j])
            {
                ci++;
            }
        }
    }
    return ci;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        memset(vis,false,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x0>>y2>>d0;
        vis[x0-1][y2-1]=true;
        for(int i=0;i<=n-1;i++)
        {
            for(int j=0;j<=m-1;j++)
            {
                cin>>mmap[i][j];
            }
        }
        while(k--)
        {
            f();
        }
        cout<<numm()<<endl;
    }
    return 0;
}