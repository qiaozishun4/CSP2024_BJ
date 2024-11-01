#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans[1005][1005],nx,ny,result;
char mp[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--)
    {
        result=0;
        for(int i=0;i<=1000;i++)
        {
            for(int j=0;j<=1000;j++)
            {
                ans[i][j]=0;
            }
        }
        cin >> n >> m >> k >> x >> y >> d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> mp[i][j];
            }
        }
        ans[x][y]=1;
        while(k--)
        {
            //cout << endl << "now at " << x << " " << y << endl;
            if(d==0)
            {
                nx=x;
                ny=y+1;
            }
            else if(d==1)
            {
                nx=x+1;
                ny=y;
            }
            else if(d==2)
            {
                nx=x;
                ny=y-1;
            }
            else if(d==3)
            {
                nx=x-1;
                ny=y;
            }
            //cout << endl << "next at " << nx << " " << ny << " " << mp[nx][ny] << endl;
            if(nx>=1 and ny>=1 and nx<=n and ny<=m and mp[nx][ny]=='.')
            {
                //cout << endl << x << " " << y << " go to " << nx << " " << ny << endl;
                x=nx;
                y=ny;
                ans[x][y]=1;
            }
            else
            {
                //cout << endl << d << " trun to ";
                d++;
                d=d%4;
                //cout << d << endl;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                result+=ans[i][j];
            }
        }
        cout << result << endl;
    }
    return 0;
}