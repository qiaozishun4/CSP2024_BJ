#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n,m,k,x,y,d;
        cin >> n >> m >> k >> x >> y >> d;
        char a[1003][1003];
        bool flag[1003][1003];
        for (int i=1;i<=n;i++)
        {
            string z;
            cin >> z;
            for (int j=1;j<=m;j++)
            {
                a[i][j]=z[j-1];
            }
        }
        flag[x][y]=1;
        for (int i=1;i<=k;i++)
        {
            if (d==0)
            {
                if (y==m || a[x][y+1]=='x')
                {
                    d++;
                    d%=4;
                }
                else
                {
                    flag[x][y+1]=1;
                    y++;
                }
            }
            else if (d==1)
            {
                if (x==n || a[x+1][y]=='x')
                {
                    d++;
                    d%=4;
                }
                else
                {
                    flag[x+1][y]=1;
                    x++;
                }
            }
            else if (d==2)
            {
                if (y==1 || a[x][y-1]=='x')
                {
                    d++;
                    d%=4;
                }
                else
                {
                    flag[x][y-1]=1;
                    y--;
                }
            }
            else
            {
                if (x==1 || a[x-1][y]=='x')
                {
                    d++;
                    d%=4;
                }
                else
                {
                    flag[x-1][y]=1;
                    x--;
                }
            }
        }
        int num=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (flag[i][j]==1)
                {
                    num++;
                }
            }
        }
        cout << num << endl;
    }
    return 0;
}
