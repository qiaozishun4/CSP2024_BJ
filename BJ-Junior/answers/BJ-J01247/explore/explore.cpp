#include <bits/stdc++.h>
using namespace std;

char mapc[1010][1010];
bool used[1010][1010];
int t=0,n=0,m=0,k=0,q=0;
int x=0,y=0,d=0,ans=0;

void go(int &x,int &y,int &d)
{
    int nx=x,ny=y;
         if(d==0) ny++;
    else if(d==1) nx++;
    else if(d==2) ny--;
    else if(d==3) nx--;
    if(nx<1||nx>n||ny<1||ny>m||mapc[nx][ny]!='.')
    {
        d++;
        if(d>3) d=0;
        return;
    }
    else
    {
             if(d==0) y++;
        else if(d==1) x++;
        else if(d==2) y--;
        else if(d==3) x--;
    }
    return;
}

int main(void)
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        memset(used,0,sizeof(used));
        memset(mapc,0,sizeof(mapc));
        ans=0,n=0,m=0,k=0,x=0,y=0,d=0,q=0;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++) scanf("%s",mapc[i]+1);
        while(q<=k)
        {
            q++;
            if(used[x][y]==false)
            {
                ans++;
                used[x][y]=true;
            }
            go(x,y,d);
        }
        cout << ans << endl;
    }
    return 0;
}
