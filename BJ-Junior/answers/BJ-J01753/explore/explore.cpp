#include<bits/stdc++.h>
using namespace std;
char ma[1005][1005];
int mn[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=1000;i++)
        {
            for(int j=1;j<=1000;j++)
            {
                ma[i][j]=0;
                mn[i][j]=0;
            }
        }
        int n,m,k,x,y,d;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        mn[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",&ma[i][1]);
            //printf("%d\n",'.');
            //printf("%d\n",ma[i][2]);
        }
        int s=1;
        for(int k1=1;k1<=k;k1++)
        {
            if(d==4)d=0;
            if(d==0)
            {
                //printf("d=%d\n",d);
                if(ma[x][y+1]==0||ma[x][y+1]=='x')
                {
                    d++;
                    continue;
                }
                y++;
                //printf("y=%d\n",y);
                if(mn[x][y]==0)
                {
                    mn[x][y]=1;
                    s++;
                }
            }
            else if(d==1)
            {
                if(ma[x+1][y]==0||ma[x+1][y]=='x')
                {
                    d++;
                    continue;
                }
                x++;
                if(mn[x][y]==0)
                {
                    mn[x][y]=1;
                    s++;
                }
            }
            else if(d==2)
            {
                //printf("d=%d\n",d);
                if(ma[x][y-1]==0||ma[x][y-1]=='x')
                {
                    d++;
                    continue;
                }
                y--;
                if(mn[x][y]==0)
                {
                    mn[x][y]=1;
                    s++;
                }
            }
            else if(d==3)
            {
                //printf("d=%d\n",d);
                if(ma[x-1][y]==0||ma[x-1][y]=='x')
                {
                    d++;
                    continue;
                }
                x--;
                if(mn[x][y]==0)
                {
                    mn[x][y]=1;
                    s++;
                }
            }
        }
        printf("%d\n",s);
    }
}
