#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1005][1005];
bool b[1005][1005];
int ans=1;
int main()
{
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        ans=1;
        for(int j=1;j<=n;j++)
        {
            for(int z=1;z<=m;z++)
            {
                cin >> a[j][z];
                b[j][z]=1;
            }
        }
        b[x][y]=0;
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                if(x<=n&&y+1<=m&&a[x][y+1]!='x')
                {
                    y+=1;
                    if(b[x][y]==1)
                    {
                        ans++;
                    }
                    b[x][y]=0;
                    continue;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==1)
            {
                if(x+1<=n&&y<=m&&a[x+1][y]!='x')
                {
                    x+=1;
                    if(b[x][y]==1)
                    {
                        ans++;
                    }
                    b[x][y]=0;
                    continue;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==2)
            {
                if(x<=n&&y-1>=1&&a[x][y-1]!='x')
                {
                    y-=1;
                    if(b[x][y]==1)
                    {
                        ans++;
                    }
                    b[x][y]=0;
                    continue;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==3)
            {
                if(x-1>=1&&y<=m&&a[x-1][y]!='x')
                {
                    x-=1;
                    if(b[x][y]==1)
                    {
                        ans++;
                    }
                    b[x][y]=0;
                    continue;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
