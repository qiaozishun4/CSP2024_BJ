#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;char ch=' ';
    while(!isdigit(ch))
        ch=getchar();
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
char gc()
{
    char p='?';
    while(p!='x' and p!='.')
        p=getchar();
    return p;
}
char mp[1050][1050];
bool vis[1050][1050];
int dy[4]={1,0,-1,0},dx[4]={0,1,0,-1};
int n,m;int cnt;
bool ir(int x,int y)
{return 1<=x and x<=n and 1<=y and y<=m;}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t=read();while(t--)
    {
        memset(vis,0,sizeof vis);
        int k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin>>mp[i][j];
        vis[x][y]=true;
        while(k--)
        {
            int xx=x+dx[d],yy=y+dy[d];
            if(ir(xx,yy) and mp[xx][yy]=='.')
                x=xx,y=yy;
            else d=(d+1)%4;
            vis[x][y]=true;
        }
        cnt=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cnt+=vis[i][j];
        cout<<cnt<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
