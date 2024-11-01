#include <iostream>
#include <cstring>

using namespace std;

char map1[1003][1003];
bool taken[1003][1003];
int n,m,k;
int x,y,d;
int ans=0;

void movem(int x,int y,int d,int t)
{
    if(t<0)
        return;
    if(!taken[x][y])
    {
        taken[x][y]=true;
        ans++;
    }
    if(d==0)
    {
        if(map1[x][y+1]=='.')
        {
            movem(x,y+1,d,t-1);
        }
        else
        {
            movem(x,y,(d+1)%4,t-1);
        }
    }
    else if(d==1)
    {
        if(map1[x+1][y]=='.')
        {
            movem(x+1,y,d,t-1);
        }
        else
        {
            movem(x,y,(d+1)%4,t-1);
        }
    }
    else if(d==2)
    {
        if(map1[x][y-1]=='.')
        {
            movem(x,y-1,d,t-1);
        }
        else
        {
            movem(x,y,(d+1)%4,t-1);
        }
    }
    else if(d==3)
    {
        if(map1[x-1][y]=='.')
        {
            movem(x-1,y,d,t-1);
        }
        else
        {
            movem(x,y,(d+1)%4,t-1);
        }
    }
}

int T;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int o=0;o<T;o++)
    {
        memset(taken,0,sizeof(taken));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>map1[i][j];
            }
        }
        movem(x,y,d,k);
        cout<<ans<<endl;
    }
    return 0;
}
