#include<bits/stdc++.h>
using namespace std;
bool a[1111][1111];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x,y,d,b=0,i,j;
    string z[1111];
    cin>>T;
    while(T--)
    {
        b=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++) cin>>z[i][j];
        }
        a[x][y]=true;
        while(k--)
        {
            if(!d)
            {
                if(y+1<=m&&z[x][y+1]=='.')
                {
                    y++;
                    a[x][y]=true;
                }
                else d=(d+1)%4;
            }
            else if(d==1)
            {
                if(x+1<=n&&z[x+1][y]=='.')
                {
                    x++;
                    a[x][y]=true;
                }
                else d=(d+1)%4;
            }
            else if(d==2)
            {
                if(y-1>=1&&z[x][y-1]=='.')
                {
                    y--;
                    a[x][y]=true;
                }
                else d=(d+1)%4;
            }
            else
            {
                if(x-1>=1&&z[x-1][y]=='.')
                {
                    x--;
                    a[x][y]=true;
                }
                else d=(d+1)%4;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]) b++;
            }
        }
        cout<<b<<endl;
    }
}
