#include <iostream>
using namespace std;
typedef long long ll;
int t;
int n, m, x, y, d, b[1010][1010];
ll k, ans=1;
char a[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for (int q=1; q<=t; ++q)
    {
        ans=1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i=1; i<=n; ++i)
        {
            for (int j=1; j<=m; ++j)
            {
                cin >> a[i][j];
                b[i][j]=0;
            }
        }
        b[x][y]=1;
        for (int i=0; i<=n+1; ++i)
        {
            a[i][0]=a[i][m+1]='x';
        }
        for (int i=0; i<=m+1; ++i)
        {
            a[0][i]=a[n+1][i]='x';
        }
        for (int i=1; i<=k; ++i)
        {
            if(d==0)
            {
                if(a[x][y+1]=='.')
                {
                    y+=1;
                    if(!b[x][y])
                    {
                        ++ans;
                        b[x][y]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==1)
            {
                if(a[x+1][y]=='.')
                {
                    x+=1;
                    if(!b[x][y])
                    {
                        ++ans;
                        b[x][y]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==2)
            {
                if(a[x][y-1]=='.')
                {
                    y-=1;
                    if(!b[x][y])
                    {
                        ++ans;
                        b[x][y]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else
            {
                if(a[x-1][y]=='.')
                {
                    x-=1;
                    if(!b[x][y])
                    {
                        ++ans;
                        b[x][y]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                }
            }
        }
        /*for (int i=1; i<=n; ++i)
        {
            for (int j=1; j<=m; ++j)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }*/
        cout << ans << endl;
    }
    return 0;
}
