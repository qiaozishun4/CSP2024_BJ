#include<cstdio>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;
bool g[1005][1005];
int f[4][2]={0,1,1,0,0,-1,-1,0};
long k;
int x,y,t,d,n,m;
string s;
bool used[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    memset(g,false,sizeof(g));
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        d%=4;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='.')
                {
                    g[i][j+1]=true;
                }
            }
        }
        int ans=1;
        used[x][y]=true;
        while(k--)
        {
            int nx=x+f[d][0];
            int ny=y+f[d][1];
            if(g[nx][ny])
            {
                x=nx;
                y=ny;
                if(!used[nx][ny])
                {
                    used[nx][ny]=true;
                    ans++;
                }
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
        memset(used,false,sizeof(used));
        memset(g,false,sizeof(g));
    }
    return 0;
}
