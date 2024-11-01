#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int id=1;id<=t;id++)
    {
        int n,m,k,ans=1;
        char s[110][110];
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>s[i][j];
            }
        }
        int dx,dy;
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                dx=0;
                dy=1;
            }
            else if(d==1)
            {
                dx=1;
                dy=0;
            }
            else if(d==2)
            {
                dx=0;
                dy=-1;
            }
            else if(d==3)
            {
                dx=-1;
                dy=0;
            }
            if(x+dx >= 1 && x+dx <= n && y+dy >= 1 && y+dy <= m && s[x+dx][y+dy] != 'X')
            {
                x+=dx;
                y+=dy;
                if(s[x][y]!='_')
                {
                    ans++;
                    s[x][y]='_';
                }
            }
            else
            {
                d = (d+1) % 4;
            }
        }
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
