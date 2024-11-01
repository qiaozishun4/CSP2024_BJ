#include <bits/stdc++.h>
using namespace std;
bool s[14],h[14],d[14],c[14];
string st;
int n,sum = 0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> st;
        if (st[0] == 'S')
        {
            if (st[1] == 'K')
                s[13] = 1;
            else if (st[1] == 'Q')
                s[12] = 1;
            else if (st[1] == 'J')
                s[11] = 1;
            else if (st[1] == 'T')
                s[10] = 1;
            else
                s[st[1] - 48] = 1;
        }
        else if (st[0] == 'H')
        {
            if (st[1] == 'K')
                h[13] = 1;
            else if (st[1] == 'Q')
                h[12] = 1;
            else if (st[1] == 'J')
                h[11] = 1;
            else if (st[1] == 'T')
                h[10] = 1;
            else
                h[st[1] - 48] = 1;
        }
        else if (st[0] == 'D')
        {
            if (st[1] == 'K')
                d[13] = 1;
            else if (st[1] == 'Q')
                d[12] = 1;
            else if (st[1] == 'J')
                d[11] = 1;
            else if (st[1] == 'T')
                d[10] = 1;
            else
                d[st[1] - 48] = 1;
        }
        else if (st[0] == 'C')
        {
            if (st[1] == 'K')
                c[13] = 1;
            else if (st[1] == 'Q')
                c[12] = 1;
            else if (st[1] == 'J')
                c[11] = 1;
            else if (st[1] == 'T')
                c[10] = 1;
            else
                c[st[1] - 48] = 1;
        }
    }
    for (int i = 1;i <= 13;i++)
    {
        if (!s[i])
            sum++;
        if (!h[i])
            sum++;
        if (!d[i])
            sum++;
        if (!c[i])
            sum++;
    }
    cout << sum;
    return 0;
}
