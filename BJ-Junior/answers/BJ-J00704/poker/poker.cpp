#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'

void write_x(long long x)
{
    if (!x)
    {
        return;
    }
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }
    write_x(x / 10);
    cout << x % 10;
}

void write(long long x, char End)
{
    if (!x)
    {
        cout << 0;
    }
    write_x(x);
    cout << End;
}

long long to_id[128];
bool hv[5][15];

void init()
{
    to_id['S'] = 1;
    to_id['C'] = 2;
    to_id['H'] = 3;
    to_id['D'] = 4;
    to_id['A'] = 1;
    to_id['2'] = 2;
    to_id['3'] = 3;
    to_id['4'] = 4;
    to_id['5'] = 5;
    to_id['6'] = 6;
    to_id['7'] = 7;
    to_id['8'] = 8;
    to_id['9'] = 9;
    to_id['T'] = 10;
    to_id['J'] = 11;
    to_id['Q'] = 12;
    to_id['K'] = 13;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    init();
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        char color = s[0], num = s[1];
        long long color_id = to_id[color], num_id = to_id[num];
        hv[color_id][num_id] = true;
    }
    long long cnt = 0;
    for (long long i = 1; i <= 4; ++i)
    {
        for (long long j = 1; j <= 13; ++j)
        {
            cnt += hv[i][j];
        }
    }
    write(52 - cnt, EOL);
    return 0;
}
