#include <bits/stdc++.h>
using namespace std;

int n;
char a[5];
int b[5][15];
int ans = 0;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a;
        int x,y = -1;
        if(a[0] == 'D')
        {
            x = 0;
        }
        if(a[0] == 'C')
        {
            x = 1;
        }
        if(a[0] == 'H')
        {
            x = 2;
        }
        if(a[0] == 'S')
        {
            x = 3;
        }
        if(a[1] == 'A')
        {
            y = 1;
        }
        if(a[1] == 'T')
        {
            y = 10;
        }
        if(a[1] == 'J')
        {
            y = 11;
        }
        if(a[1] == 'Q')
        {
            y = 12;
        }
        if(a[1] == 'K')
        {
            y = 13;
        }
        if(y == -1)
        {
            y = a[1] - '0';
        }
        b[x][y]++;
    }
    for(int i = 0;i <= 3;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            if(!b[i][j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
