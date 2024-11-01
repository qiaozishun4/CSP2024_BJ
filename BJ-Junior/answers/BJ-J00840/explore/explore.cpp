#include <iostream>
#include <string>
using namespace std;
struct pos
{
    int x;
    int y;
    short d;//fangxiang
};
pos robot;
int t,n,m,k;

char c[1002][1002];
bool vis[1002][1002];
bool check(int x,int y)
{
    return (x<=n&&y<=m&&x>=1&&y>=1&&c[x][y]=='.');
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>robot.x>>robot.y>>robot.d;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }

        int cnt;
        for(int i=1;i<=4;i++)
        {
            if(robot.d==0)
            {
                if(check(robot.x,robot.y+1))
                {
                    vis[robot.x][robot.y]=1;
                }
            }
            else if(robot.d==1)
            {
                if(check(robot.x+1,robot.y))
                {
                    vis[robot.x][robot.y]=1;
                }
            }
            else if(robot.d==2)
            {
                if(check(robot.x,robot.y-1))
                {
                    vis[robot.x][robot.y]=1;
                }
            }
            else if(robot.d==3)
            {
                if(check(robot.x-1,robot.y))
                {
                    vis[robot.x][robot.y]=1;
                }
            }
            robot.d=(robot.d+1)%4;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(vis[i][j]==1)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
