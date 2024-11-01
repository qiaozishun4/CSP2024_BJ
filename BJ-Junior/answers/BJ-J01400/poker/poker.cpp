#include <bits/stdc++.h>
using namespace std;
int d[15], c[15], h[15], s[15];
int main()
{
  freopen("poker.in", "r", stdin);
  freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        char ca, cb;
        cin >> ca >> cb;
        if(ca == 'D')
        {
            if(cb == 'A')
            {
                d[1] ++;
            }
            if(cb == '2')
            {
                d[2] ++;
            }
            if(cb == '3')
            {
                d[3] ++;
            }
            if(cb == '4')
            {
                d[4] ++;
            }
            if(cb == '5')
            {
                d[5] ++;
            }
            if(cb == '6')
            {
                d[6] ++;
            }
            if(cb == '7')
            {
                d[7] ++;
            }
            if(cb == '8')
            {
                d[8] ++;
            }
            if(cb == '9')
            {
                d[9] ++;
            }
            if(cb == 'T')
            {
                d[10] ++;
            }
            if(cb == 'J')
            {
                d[11] ++;
            }
            if(cb == 'Q')
            {
                d[12] ++;
            }
            if(cb == 'K')
            {
                d[13] ++;
            }
        }
        if(ca == 'C')
        {
            if(cb == 'A')
            {
                c[1] ++;
            }
            if(cb == '2')
            {
                c[2] ++;
            }
            if(cb == '3')
            {
                c[3] ++;
            }
            if(cb == '4')
            {
                c[4] ++;
            }
            if(cb == '5')
            {
                c[5] ++;
            }
            if(cb == '6')
            {
                c[6] ++;
            }
            if(cb == '7')
            {
                c[7] ++;
            }
            if(cb == '8')
            {
                c[8] ++;
            }
            if(cb == '9')
            {
                c[9] ++;
            }
            if(cb == 'T')
            {
                c[10] ++;
            }
            if(cb == 'J')
            {
                c[11] ++;
            }
            if(cb == 'Q')
            {
                c[12] ++;
            }
            if(cb == 'K')
            {
                c[13] ++;
            }
        }
        if(ca == 'H')
        {
            if(cb == 'A')
            {
                h[1] ++;
            }
            if(cb == '2')
            {
                h[2] ++;
            }
            if(cb == '3')
            {
                h[3] ++;
            }
            if(cb == '4')
            {
                h[4] ++;
            }
            if(cb == '5')
            {
                h[5] ++;
            }
            if(cb == '6')
            {
                h[6] ++;
            }
            if(cb == '7')
            {
                h[7] ++;
            }
            if(cb == '8')
            {
                h[8] ++;
            }
            if(cb == '9')
            {
                h[9] ++;
            }
            if(cb == 'T')
            {
                h[10] ++;
            }
            if(cb == 'J')
            {
                h[11] ++;
            }
            if(cb == 'Q')
            {
                h[12] ++;
            }
            if(cb == 'K')
            {
                h[13] ++;
            }
        }
        if(ca == 'S')
        {
            if(cb == 'A')
            {
                s[1] ++;
            }
            if(cb == '2')
            {
                s[2] ++;
            }
            if(cb == '3')
            {
                s[3] ++;
            }
            if(cb == '4')
            {
                s[4] ++;
            }
            if(cb == '5')
            {
                s[5] ++;
            }
            if(cb == '6')
            {
                s[6] ++;
            }
            if(cb == '7')
            {
                s[7] ++;
            }
            if(cb == '8')
            {
                s[8] ++;
            }
            if(cb == '9')
            {
                s[9] ++;
            }
            if(cb == 'T')
            {
                s[10] ++;
            }
            if(cb == 'J')
            {
                s[11] ++;
            }
            if(cb == 'Q')
            {
                s[12] ++;
            }
            if(cb == 'K')
            {
                s[13] ++;
            }
        }
    }
    int ans = 52;
    for(int i = 1; i <= 13; i ++)
    {
        if(d[i] != 0) ans --;
        if(c[i] != 0) ans --;
        if(s[i] != 0) ans --;
        if(h[i] != 0) ans --;
    }
    cout << ans;
  fclose(stdin);
  fclose(stdout);
    return 0;
}
