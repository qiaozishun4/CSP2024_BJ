#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int xd[4]={0,1,0,-1},yd[4]={1,0,-1,0};
char c;
bool mp[1003][1003];
int mem[1003][1003];
int sum;
int tx,ty;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        mem[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='.')
                {
                    mp[i][j]=1;
                }
            }
        }
        while(k--)
        {
            tx=x+xd[d];
            ty=y+yd[d];
            if(tx>=0&&ty>=0&&tx<=n&&ty<=m&&mp[tx][ty])
            {
                x=tx,y=ty;
                mem[x][y]=1;
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
                mp[i][j]=0;
                sum+=mem[i][j];
                mem[i][j]=0;
            }
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}
