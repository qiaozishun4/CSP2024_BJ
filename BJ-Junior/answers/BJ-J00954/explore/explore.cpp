#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
char Map[102][102];
bool bmap[102][102];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    string tmp;
    short t,x,y,d;
    int n=0,m=0,k=0,sum=1;
    cin>>t;
    for(int i=0;i<t;i++)
    {

        cin>>n>>m>>k;
        cin>>x>>y>>d;
        bmap[x][y]=true;
        for(int j=1;j<=n;j++)
        {
            cin>>tmp;
            int kk=0;
            for(kk=1;kk<=m;kk++)
            {
                Map[j][kk]=tmp[kk-1];
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int kk=1;kk<=m;kk++)
            {
                bmap[j][kk]=false;
            }
        }
        for(int j=1;j<=k;j++)
        {
            //cout<<j<<x<<y<<d;
            if(d==0&&x>0&&x<=n&&y>0&&y+1<=m&&Map[x][y+1]!='X')
            {
                y++;
                if(bmap[x][y]==false)
                {
                    sum++;
                }
                bmap[x][y]=true;
                continue;
            }
            else if(d==1&&x>0&&x+1<=n&&y>0&&y<=m&&Map[x+1][y]!='X')
            {
                x++;
                if(bmap[x][y]==false)
                {
                    sum++;
                }
                bmap[x][y]=true;
                continue;
            }
            else if(d==2&&x>0&&x<=n&&y-1>0&&y<=m&&Map[x][y-1]!='X')
            {
                y--;
                if(bmap[x][y]==false)
                {
                    sum++;
                }
                bmap[x][y]=true;
                continue;
            }
            else if(d==3&&x-1>0&&x<=n&&y>0&&y<=m&&Map[x-1][y]!='X')
            {
                x--;
                if(bmap[x][y]==false)
                {
                    sum++;
                }
                bmap[x][y]=true;
                continue;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}
