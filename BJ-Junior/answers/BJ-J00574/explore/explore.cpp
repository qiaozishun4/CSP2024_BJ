#include <bits/stdc++.h>
using namespace std;

int k, d, Rx, Ry, t, n, m;
int Yx, Yy;
int sum, samE;
char m_Map[1001][1001];

void RGo()
{
    int x2, y2;
    x2 = Rx;
    y2 = Ry;
    if(d == 0)
        y2 = Ry+1;
    else if(d == 1)
        x2 = Rx+1;
    else if(d == 2)
        y2 = Ry-1;
    else if(d == 3)
        x2 = Rx-1;
    if(x2 >= 1 && y2>=1 && x2 <= n && y2 <= m && m_Map[x2][y2] != 'x')
    {
        Rx = x2;
        Ry = y2;
        if(m_Map[x2][y2] == '.')
        {
            sum++;
            m_Map[x2][y2] = 'k';
        }
        if(x2 == Yx && y2 == Yy)
            samE++;
    }
    else
        d = (d+1)%4;
    return;
}

int main()
{
    freopen("explore5.in","r",stdin);
    freopen("explore5.out","w",stdout);

    scanf("%d", &t);
    while(t)
    {
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d", &Rx, &Ry, &d);
        sum = 1; samE = 0;
        m_Map[Rx][Ry] = 'k';
        Yx = Rx;
        Yy = Ry;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                cin>>m_Map[i][j];
            }
        }

        for(int z = 1;z<=k;z++)
        {
            RGo();
        }
        if(samE%2 == 1)
            sum--;
        printf("%d\n", sum);

        t--;
    }

    return 0;
}
