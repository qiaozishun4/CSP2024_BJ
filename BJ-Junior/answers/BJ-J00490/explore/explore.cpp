#include<bits/stdc++.h>
using namespace std;

char c[1010][1010];
int vis[1010][1010];
int n,m,k,x,y,d;
int opx[5]={0,1,0,-1},opy[5]={1,0,-1,0};

bool check(int x,int y)
{
    if(x<0)
        return false;
    if(x>=n)
        return false;
    if(y<0)
        return false;
    if(y>=m)
        return false;
    if(c[x][y]=='x')
        return false;
    return true;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        int ans=1;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        x--;
        y--;
        vis[x][y]=1;
        for(int i=0;i<n;i++)
            scanf("%s",c[i]);
        while(k--)
        {
            if(check(x+opx[d],y+opy[d]))
            {
                x+=opx[d];
                y+=opy[d];
                if(!vis[x][y])
                    ans++;
                vis[x][y]=1;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
