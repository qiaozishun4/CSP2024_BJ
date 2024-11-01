#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool vis[1010][1010];
bool OK[1010][1010];
bool isin(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long cnt=1;
        scanf("%d%d%d",&n,&m,&k);
        int sx,sy,d;
        scanf("%d%d%d",&sx,&sy,&d);
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='x')
                    OK[i][j+1]=true;
                else
                {
                    vis[i][j+1]=false;
                    OK[i][j+1]=false;
                }
            }
        }
        int x=sx,y=sy;
        vis[x][y]=true;
        while(k--)
        {
            if(d==0&&isin(x,y+1)&&!OK[x][y+1])
            {
                y++;
                if(!vis[x][y])
                {
                    cnt++;
                    vis[x][y]=true;
                }
            }
            else if(d==1&&isin(x+1,y)&&!OK[x+1][y])
            {
                x++;
                if(!vis[x][y])
                {
                    cnt++;
                    vis[x][y]=true;
                }
            }
            else if(d==2&&isin(x,y-1)&&!OK[x][y-1])
            {
                y--;
                if(!vis[x][y])
                {
                    cnt++;
                    vis[x][y]=true;
                }
            }
            else if(d==3&&isin(x-1,y)&&!OK[x-1][y])
            {
                x--;
                if(!vis[x][y])
                {
                    cnt++;
                    vis[x][y]=true;
                }
            }
            else
                d=(d+1)%4;
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
