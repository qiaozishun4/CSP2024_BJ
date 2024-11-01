#include<iostream>
#include<cstdio>
using namespace std;
char c[2000][2000];
bool f[2000][2000];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int j=1;j<=1000;j++)
            for(int l=1;l<=1000;l++)
                f[j][l]=0,c[j][l]=0;
        for(int j=1;j<=n;j++)
            for(int l=1;l<=m;l++)
                cin>>c[j][l];
        f[x][y]=1;
        for(int j=1;j<=k;j++)
        {
            f[x][y]=1;
            if(d==0)
            {
                if((x<1)||(x>n)||(y+1<1)||(y+1>m)||(c[x][y+1]=='x'))
                    d=1;
                else
                    y++;
            }
            else if(d==1)
            {
                if((x+1<1)||(x+1>n)||(y<1)||(y>m)||(c[x+1][y]=='x'))
                    d=2;
                else
                    x++;
            }
            else if(d==2)
            {
                if((x<1)||(x>n)||(y-1<1)||(y-1>m)||(c[x][y-1]=='x'))
                    d=3;
                else
                    y--;
            }
            else
            {
                if((x-1<1)||(x-1>n)||(y<1)||(y>m)||(c[x-1][y]=='x'))
                    d=0;
                else
                    x--;
            }
            f[x][y]=1;
        }
        f[x][y]=1;
        int cnt=0;
        for(int j=1;j<=n;j++)
            for(int l=1;l<=m;l++)
                if(f[j][l])
                    cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}