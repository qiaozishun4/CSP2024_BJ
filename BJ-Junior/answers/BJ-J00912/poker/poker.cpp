#include <bits/stdc++.h>
using namespace std;

int pk[5][14];
int ex[150];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n = 0;
    int ans = 0;
    string cur;
    ex['A'] = 1;
    ex['2'] = 2;
    ex['3'] = 3;
    ex['4'] = 4;
    ex['5'] = 5;
    ex['6'] = 6;
    ex['7'] = 7;
    ex['8'] = 8;
    ex['9'] = 9;

    ex['T'] = 10;
    ex['J'] = 11;
    ex['Q'] = 12;
    ex['K'] = 13;

    ex['D'] = 1;
    ex['C'] = 2;
    ex['H'] = 3;
    ex['S'] = 4;

    cin >> n;
    for (int i = 1 ; i <=n ; i++)
    {
        cin >> cur;
        int row = ex[cur[0]];
        int col = ex[cur[1]];

        if (pk[row][col] == 0)
        {
            ans ++;
            pk[row][col] ++;
        }

    }

    cout << 52 - ans;


    return 0;
}
