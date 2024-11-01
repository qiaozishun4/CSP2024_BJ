#include <bits/stdc++.h>
using namespace std;

int n,a[5][14];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);


    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        char x,y;
        cin >> x >> y;
        int m;
        if (y >= '0' && y <= '9')
        {
            m = y-'0';
        }
        else
        {
            if (y == 'T')
            {
                m = 10;
            }
            else if (y == 'J')
            {
                m = 11;
            }
            else if (y == 'Q')
            {
                m = 12;
            }
            else if (y == 'K')
            {
                m = 13;
            }
            else if (y == 'A')
            {
                m = 1;
            }
        }
        if (x == 'D')
        {
            a[1][m]++;
        }
        else if (x == 'C')
        {
            a[2][m]++;
        }
        else if (x == 'H')
        {
            a[3][m]++;
        }
        else if (x == 'S')
        {
            a[4][m]++;
        }
    }

    int s = 52;
    for (int i = 1;i <= 4;i++)
    {
        for (int j = 1;j <= 13;j++)
        {
            if (a[i][j] >= 1)
            {
                s--;
            }
        }
    }
    cout << s;



    return 0;
}
