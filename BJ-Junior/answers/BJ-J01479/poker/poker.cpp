#include <bits/stdc++.h>
using namespace std;
int r[50][50];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w",stdout);
    int n;
    cin >> n;
    int cnt = 0;
    while(n--)
    {
        char a, b;
        cin >> a >> b;
        int c = 0, d = 0;
        if(b >= '2' && b <= '9')
        {
            d = b - '0';
        }else if(b == 'A')
        {
            d = 1;
        }else if(b == 'T')
        {
            d = 10;
        }else if(b == 'J')
        {
            d = 11;
        }else if(b == 'Q')
        {
            d = 12;
        }else if(b == 'K'){
            d = 13;
        }
        if(a == 'D')
        {
            c = 1;
            if(r[c][d] == 1)
            {
                cnt += 0;
            }else
            {
                cnt++;
                r[c][d] = 1;
            }
        }else if(a == 'C')
        {
            c = 2;
            if(r[c][d] == 1)
            {
                cnt = cnt;
            }else
            {
                cnt++;
                r[c][d] = 1;
            }
        }else if(a == 'H')
        {
            c = 3;
            if(r[c][d] == 1)
            {
                cnt = cnt;
            }else
            {
                cnt++;
                r[c][d] = 1;
            }
        }else if(a == 'S')
        {
            c = 4;
            if(r[c][d] == 1)
            {
                cnt = cnt;
            }else
            {
                cnt++;
                r[c][d] = 1;
            }
        }
    }
    cout << 52 - cnt;
    return 0;
}