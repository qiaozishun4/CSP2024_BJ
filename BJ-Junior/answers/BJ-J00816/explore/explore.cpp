#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k,x,y,d,xx,yy,s=0;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        b[x][y]=1;
        xx=x;yy=y;
        for(int j=1;j<=n;j++){
            string u;
            cin>>u;
            for(int w=0;w<m;w++)
                a[j][w+1]=u[w];

        }
        for(int j=1;j<=k;j++)
        {
            switch(d)
            {
            case 0:yy++;break;
            case 1:xx++;break;
            case 2:yy--;break;
            case 3:xx--;break;
            }
            if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&a[xx][yy]=='.')
            {
                x=xx;
                y=yy;
                b[x][y]=1;
            }
            else
            {
                d=(d+1)%4;
                xx=x;
                yy=y;
            }

        }
        for(int j=1;j<=n;j++)
            for(int w=1;w<=m;w++)
                s+=b[j][w];
        printf("%d\n",s);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                a[i][j]=b[i][j]=0;
    }
    return 0;
}
