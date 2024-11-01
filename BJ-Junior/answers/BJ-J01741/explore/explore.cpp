#include <iostream>

using namespace std;
int n,m,k,d[1000005],x[1000005],y[1000005];
char a[1005][1005];
int b[1005][1005] = {0};
int t;
int ans = 1;
void go(int i)
{
    if(d[i] == 0)
    {
        if(y[i] + 1 <= m &&a[x[i]][y[i] + 1] == '.')
        {
            if(b[x[i]][y[i] + 1] == 0) ans++;
            b[x[i]][y[i] + 1] = 1;
            x[i + 1] = x[i];
            y[i + 1] = y[i] + 1;
            d[i + 1] = d[i];

        }
        else
        {
            d[i + 1] = (d[i] + 1)%4;
            x[i + 1] = x[i];
            y[i + 1] = y[i];
        }

    }

    else if(d[i] == 1)
    {
        if(x[i] + 1 <= n &&a[x[i] + 1][y[i]] == '.')
        {
            if(b[x[i] + 1][y[i]] == 0) ans++;
            b[x[i] + 1][y[i]] = 1;
            x[i + 1] = x[i]+ 1;
            y[i + 1] = y[i];
            d[i + 1] = d[i];
        }
        else
        {
            d[i + 1] = (d[i] + 1)%4;
            x[i + 1] = x[i];
            y[i + 1] = y[i];
        }
    }
    else if(d[i] == 2)
    {
        if(y[i] - 1 >= 1 &&a[x[i]][y[i] - 1] == '.')
        {
            if(b[x[i]][y[i] - 1] == 0) ans++;
            b[x[i]][y[i] - 1] = 1;
            x[i + 1] = x[i];
            y[i + 1] = y[i] - 1;
            d[i + 1] = d[i];
        }
        else
        {
            d[i + 1] = (d[i] + 1)%4;
            x[i + 1] = x[i];
            y[i + 1] = y[i];
        }
    }

    else if(d[i] == 3)
    {
        if(x[i] - 1 >= 1 &&a[x[i] - 1][y[i]] == '.')
        {
            if(b[x[i] - 1][y[i]] == 0) ans++;
            b[x[i] - 1][y[i]] = 1;
            x[i + 1] = x[i] - 1;
            y[i + 1] = y[i];
            d[i + 1] = d[i];
        }
        else
        {
            d[i + 1] = (d[i] + 1)%4;
            x[i + 1] = x[i];
            y[i + 1] = y[i];
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>t;
    while(t--)
    {

        ans = 1;
        cin>>n>>m>>k;
        cin>>x[0]>>y[0]>>d[0];
        for(int i = 1;i <= n;i ++)
        {
            for(int j = 1;j <= m;j ++)
            {
                cin>>a[i][j];
                b[i][j] = 0;
            }
        }
        b[x[0]][y[0]] = 1;
        for(int i = 0;i < k;i ++)
        {
            go(i);
        }
        cout<<ans<<endl;
    }

    return 0;
}
