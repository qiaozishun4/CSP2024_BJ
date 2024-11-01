#include<bits/stdc++.h>
using namespace std;
int g,n,m,k,x,y,d,c=1;
string in;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>g;
    for(int i=0;i<g;i++)
    {
        cin>>n>>m>>k;
        char map[1001][1001],tof[1001][1001];
        cin>>x>>y>>d;
        tof[x][y]='1';
        c=1;
        for(int j=1;j<=n;j++)
        {
            cin>>in;
            for(int l=1;l<=m;l++)
            {
                map[j][l]=in[l-1];
                tof[j][l]='0';
            }
        }
        while(k)
        {
            if(d==0&&y+1<=m&&map[x][y+1]=='.')
            {
                y++;
                if(tof[x][y]=='0')
                {
                    c++;
                    tof[x][y]='1';
                }
            }
            else if(d==1&&x+1<=n&&map[x+1][y]=='.')
            {
                x++;
                if(tof[x][y]=='0')
                {
                    c++;
                    tof[x][y]='1';
                }
            }
            else if(d==2&&y-1>=1&&map[x][y-1]=='.')
            {
                y--;
                if(tof[x][y]=='0')
                {
                    c++;
                    tof[x][y]='1';
                }
            }
            else if(d==3&&x-1>=1&&map[x-1][y]=='.')
            {
                x--;
                if(tof[x][y]=='0')
                {
                    c++;
                    tof[x][y]='1';
                }
            }
            else
            {
                d=(d+1)%4;
            }
            k--;
        }
        cout<<c<<endl;
    }
    return 0;
}