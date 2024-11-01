#include <bits/stdc++.h>
using namespace std;

char fmap[1010][1010];
int mappass[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int dc;//数据数量
    cin>>dc;
    for(int i=0;i<dc;i++)
    {
        for(int j=0;j<1010;j++)
        {
            for(int h=0;h<1010;h++)
            {
                fmap[j][h]='x';
                mappass[j][h]=0;
            }
        }
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        mappass[x][y]=1;
        for(int j=1;j<=n;j++)
        {
            for(int h=1;h<=m;h++)
            {
                cin>>fmap[j][h];

                //cout<<fmap[j][h]<<' ';
            }
            //cout<<endl;
        }
        int passcount=1;
        while(k>0)
        {
            if(d==0)
            {
                if(fmap[x][y+1]=='x')
                {
                    d++;
                    d=d%4;
                }else
                {
                    y++;
                }
            }else if(d==1)
            {
                if(fmap[x+1][y]=='x')
                {
                    d++;
                    d=d%4;
                }else
                {
                    x++;
                }
            }else if(d==2)
            {
                if(fmap[x][y-1]=='x')
                {
                    d++;
                    d=d%4;
                }else
                {
                    y--;
                }
            }else if(d==3)
            {
                if(fmap[x-1][y]=='x')
                {
                    d++;
                    d=d%4;
                }else
                {
                    x--;
                }
            }
            //cout<<x<<' '<<y<<' '<<d<<endl;
            if(mappass[x][y]!=1)
            {
                mappass[x][y]=1;
                passcount++;
            }
            k--;
        }
        cout<<passcount<<endl;
    }
    return 0;
}
