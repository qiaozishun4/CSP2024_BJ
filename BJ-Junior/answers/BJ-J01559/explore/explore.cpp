#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,ans,x,y,d,newx,newy;
bool M[1010][1010],mp[1010][1010];
char c;
int fx[4][2]={0,1,1,0,0,-1,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        ans=1;
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= m;++j)
            {
                M[i][j]=0;
            }
        }
        scanf("%d%d%d",&x,&y,&d);
        getchar();
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= m;++j)
            {
                c=getchar();
                if(c=='.') mp[i][j]=0;
                else mp[i][j]=1;
            }
            getchar();
        }
        //++k;
        while(k--)
        {
            newx=x+fx[d][0];
            newy=y+fx[d][1];
            if(newx>n||newx<1||newy>m||newy<1||mp[newx][newy])
            {
                d=(d+1)%4;
            }
            else
            {
                x=newx;
                y=newy;
                if(!M[x][y])
                {
                    ++ans;
                    M[x][y]=1;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
