#include <bits/stdc++.h>
using namespace std;
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
char a[1005][1005];
int s[5][1005][1005];
int sum,u;
bool check(int x,y)
{
    if(x<1||x>n||y<1||y>m||a[x][y]=='x')
    {
        return false;
    }
    return true;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int c=0;c<t;c++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        s[c][x][y]=1;
        while(u<k)
        {
            for(int i=d;i<4;i=(i+1)%4)
            {
                int tmpx=x+fx[i];
                int tmpy=y+fy[i];
                if(check(tmpy,tmpx)==true)
                {
                    x=tmpx;
                    y=tmpy;
                    s[c][tmpx][tmpy]=1;
                    u++;
                    break;
                }
                u++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[c][i][j]==1)
                {
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
}
