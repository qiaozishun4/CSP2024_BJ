#include <iostream>
using namespace std;
long long map[1005][1005],k,m,n,t,x,y,d,sum,x1,y1;
bool isgo[1005][1005];
char xi;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int o=1;o<=t;o++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;

        isgo[x][y]=1;
        sum=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>xi;
                if(xi=='.')
                {
                    map[i][j]=1;
                }
                else
                {
                    map[i][j]=0;
                }
            }
        }

        for(int i=1;i<=k;i++)
        {

            if(d==0)
            {
                y1=y+1;
                x1=x;
            }
            else if(d==1)
            {
                y1=y;
                x1=x+1;
            }
            else if(d==2)
            {
                y1=y-1;
                x1=x;
            }
            else if(d==3)
            {
                y1=y;
                x1=x-1;
            }

            if(1<=x1&&x1<=n&&1<=y1&&y1<=m&&map[x1][y1]==1)
            {
                x=x1;
                y=y1;

                if(isgo[x][y]==false)
                {

                    sum++;

                    isgo[x][y]=true;
                }

            }
            else
            {

                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                isgo[i][j]=false;
                map[i][j]=0;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
