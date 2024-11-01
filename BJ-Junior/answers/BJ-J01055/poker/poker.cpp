#include <iostream>
using namespace std;

int x[10][20];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n; i++)
    {
        string s;
        cin >> s;
        if(s[0] == 'D')
        {
            if(s[1] >= '0' && s[1] <= '9') x[1][s[1] - '0'] = 1;
            if(s[1] == 'A') x[1][1] = 1;
            if(s[1] == 'T') x[1][10] = 1;
            if(s[1] == 'J') x[1][11] = 1;
            if(s[1] == 'Q') x[1][12] = 1;
            if(s[1] == 'K') x[1][13] = 1;
        }
        if(s[0] == 'C')
        {
            if(s[1] >= '0' && s[1] <= '9') x[2][s[1] - '0'] = 1;
            if(s[1] == 'A') x[2][1] = 1;
            if(s[1] == 'T') x[2][10] = 1;
            if(s[1] == 'J') x[2][11] = 1;
            if(s[1] == 'Q') x[2][12] = 1;
            if(s[1] == 'K') x[2][13] = 1;
        }
        if(s[0] == 'H')
        {
            if(s[1] >= '0' && s[1] <= '9') x[3][s[1] - '0'] = 1;
            if(s[1] == 'A') x[3][1] = 1;
            if(s[1] == 'T') x[3][10] = 1;
            if(s[1] == 'J') x[3][11] = 1;
            if(s[1] == 'Q') x[3][12] = 1;
            if(s[1] == 'K') x[3][13] = 1;
        }
        if(s[0] == 'S')
        {
            if(s[1] >= '0' && s[1] <= '9') x[4][s[1] - '0'] = 1;
            if(s[1] == 'A') x[4][1] = 1;
            if(s[1] == 'T') x[4][10] = 1;
            if(s[1] == 'J') x[4][11] = 1;
            if(s[1] == 'Q') x[4][12] = 1;
            if(s[1] == 'K') x[4][13] = 1;
        }
    }
    int cnt = 0;
    for(int i = 1;i <= 4; i++)
        for(int j = 1;j <= 13; j++)
            if(!x[i][j]) cnt++;
    cout << cnt << endl;
    return 0;
}
