#include <bits/stdc++.h>
using namespace std;

char a[105][105];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k,x,y,d;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i  = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        int x1=x,y1=y;
        if(d==0)
            y1++;
        else if(d==1)
            x1++;
        else if(d==2)
            y1--;
        else
            x1--;
        if(k==1)
        {
            if((x1>=1&&x1<=n)&&(y1>=1&&y1<=m)&&(a[x1][y1]=='.'))
            {
                cout << 2;
            }
            else
            {
                cout << 1;
            }
        }
    }
    return 0;
}