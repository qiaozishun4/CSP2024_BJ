#include <iostream>
#include <cstdio>
using namespace std;


int colorTable[256], valueTable[256];
bool mp[20][20];


int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    colorTable['D'] = 1;
    colorTable['C'] = 2;
    colorTable['H'] = 3;
    colorTable['S'] = 4;

    valueTable['A'] = 1;
    valueTable['2'] = 2;
    valueTable['3'] = 3;
    valueTable['4'] = 4;
    valueTable['5'] = 5;
    valueTable['6'] = 6;
    valueTable['7'] = 7;
    valueTable['8'] = 8;
    valueTable['9'] = 9;
    valueTable['T'] = 10;
    valueTable['J'] = 11;
    valueTable['Q'] = 12;
    valueTable['K'] = 13;

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        char color, value;
        cin >> color >> value;
        int c = colorTable[color], v = valueTable[value];
        mp[c][v] = true;
    }

    int ans = 0;
    for(int i = 1; i <= 4; ++i)
    {
        for(int j = 1; j <= 13; ++j)
        {
            if(!mp[i][j])
                ans++;
        }
    }
    cout << ans << endl;


    return 0;
}
