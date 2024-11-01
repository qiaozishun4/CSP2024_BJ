#include <iostream>
using namespace std;
char c[1005][1005];
bool w[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x0,y0,x1,y1,d0,s,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x0,&y0,&d0);
        x0--,y0--,s=0,w[x0][y0]=1;
        for(i=0;i<n;i++)
            scanf("%s",c+i);
        while(k--)
        {
            switch(d0)
            {
                case 0:x1=x0;y1=y0+1;break;
                case 1:x1=x0+1;y1=y0;break;
                case 2:x1=x0;y1=y0-1;break;
                case 3:x1=x0-1;y1=y0;
            }
            if(x1>=n||x1<0||y1>=m||y1<0)
            {
                d0=(d0+1)%4;
                continue;
            }
            if(c[x1][y1]=='x')
                d0=(d0+1)%4;
            else
            {
                w[x1][y1]=1;
                x0=x1,y0=y1;
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(w[i][j])
                    s++,w[i][j]=0;
        printf("%d\n",s);
    }
    return 0;
}