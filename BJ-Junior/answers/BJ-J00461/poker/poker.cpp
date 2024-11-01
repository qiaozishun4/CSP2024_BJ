#include <iostream>
#include <cstdio>
using namespace std;

int p[5][15];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ph, ps;
        cin >> ph >> ps;
        int pi, pj;
        if (ph == 'D') pi = 1;
        else if (ph == 'C') pi = 2;
        else if (ph == 'H') pi = 3;
        else pi = 4;
        if (ps == 'A') pj = 1;
        else if (ps == '2') pj = 2;
        else if (ps == '3') pj = 3;
        else if (ps == '4') pj = 4;
        else if (ps == '5') pj = 5;
        else if (ps == '6') pj = 6;
        else if (ps == '7') pj = 7;
        else if (ps == '8') pj = 8;
        else if (ps == '9') pj = 9;
        else if (ps == 'T') pj = 10;
        else if (ps == 'J') pj = 11;
        else if (ps == 'Q') pj = 12;
        else pj = 13;
        p[pi][pj]++;
    }
    int cnt = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (p[i][j] == 0) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
