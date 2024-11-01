#include<iostream>
using namespace std;
char g[1010][1010];
long long T,n,m,k;
long long x,y,d;
long long ans;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>g[i][j];
        g[x][y]='#';
        while(k--)
        {
            if(d==0)
            {
                if(y+1>=1&&y+1<=m&&g[x][y+1]!='x')
                {
                    y++;
                    g[x][y]='#';
                }
                else d=(d+1)%4;
            }
            else if(d==1)
            {
                if(x+1>=1&&x+1<=n&&g[x+1][y]!='x')
                {
                    x++;
                    g[x][y]='#';
                }
                else d=(d+1)%4;
            }
            else if(d==2)
            {
                if(y-1>=1&&y-1<=m&&g[x][y-1]!='x')
                {
                    y--;
                    g[x][y]='#';
                }
                else d=(d+1)%4;
            }
            else if(d==3)
            {
                if(x-1>=1&&x-1<=n&&g[x-1][y]!='x')
                {
                    x--;
                    g[x][y]='#';
                }
                else d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(g[i][j]=='#') ans++;
        cout<<ans<<endl;
    }
    return 0;
}
