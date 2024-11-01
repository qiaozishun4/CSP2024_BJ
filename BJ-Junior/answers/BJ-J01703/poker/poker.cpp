#include <bits/stdc++.h>
using namespace std;

bool myflag[5][15];

int main()
{
    freopen ("poker.in", "r", stdin);
    freopen ("poker.out", "w", stdout);
    int myn;
    cin >> myn;
    for (int i = 1; i <= myn; i++)
    {
        string mys;
        cin >> mys;
        int ma, mb;
        if (mys[0] == 'D') ma = 1;
        else if (mys[0] == 'C') ma = 2;
        else if (mys[0] == 'H') ma = 3;
        else if (mys[0] == 'S') ma = 4;
        if (mys[1] < '0' || mys[1] > '9')
        {
            if (mys[1] == 'A') mb = 1;
            else if (mys[1] == 'T') mb = 10;
            else if (mys[1] == 'J') mb = 11;
            else if (mys[1] == 'Q') mb = 12;
            else if (mys[1] == 'K') mb = 13;
        }
        else
        {
            mb = int(mys[1] - '0');
        }
        myflag[ma][mb] = true;
    }
    int mcnt = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 13; j++)
            if(!myflag[i][j]) ++mcnt;
    cout << mcnt << endl;
    return 0;
}
