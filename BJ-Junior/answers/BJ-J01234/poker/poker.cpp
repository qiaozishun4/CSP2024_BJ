#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool bl[10][20];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char a, b;
        cin >> a >> b;
        int c;
        if (b == 'A') c = 1;
        else if (b == 'T') c = 10;
        else if (b == 'J') c = 11;
        else if (b == 'Q') c = 12;
        else if (b == 'K') c = 13;
        else if ('0' <= b && '9' >= b) c = b - '0';
        if (a == 'D')
        {
            if (!bl[1][c])
            {
                bl[1][c] = true;
                cnt++;
            }
        }
        else if (a == 'C')
        {
            if (!bl[2][c])
            {
                bl[2][c] = true;
                cnt++;
            }
        }
        else if (a == 'H')
        {
            if (!bl[3][c])
            {
                bl[3][c] = true;
                cnt++;
            }
        }
        else if (a == 'S')
        {
            if (!bl[4][c])
            {
                bl[4][c] = true;
                cnt++;
            }
        }
    }
    cout << (52 - cnt) << endl;

    return 0;
}
