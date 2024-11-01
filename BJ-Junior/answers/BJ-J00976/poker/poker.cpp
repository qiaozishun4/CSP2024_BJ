#include <bits/stdc++.h>
using namespace std;

bool d[20], c[20], h[20], s[20];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char hua, dian;
        cin >> hua >> dian;
        if(hua == 'D')
        {
            if (dian == '2' || dian == '3' || dian == '4' || dian == '5' || dian == '6' || dian == '7' || dian == '8' || dian == '9')
            {
                d[dian - '0'] = true;
            }
            if (dian == 'A')
            {
                d[1] = true;
            }
            if (dian == 'T')
            {
                d[10] = true;
            }
            if (dian == 'J')
            {
                d[11] = true;
            }
            if (dian == 'Q')
            {
                d[12] = true;
            }
            if (dian == 'K')
            {
                d[13] = true;
            }
        }
        if(hua == 'C')
        {
            if (dian == '2' || dian == '3' || dian == '4' || dian == '5' || dian == '6' || dian == '7' || dian == '8' || dian == '9')
            {
                c[dian - '0'] = true;
            }
            if (dian == 'A')
            {
                c[1] = true;
            }
            if (dian == 'T')
            {
                c[10] = true;
            }
            if (dian == 'J')
            {
                c[11] = true;
            }
            if (dian == 'Q')
            {
                c[12] = true;
            }
            if (dian == 'K')
            {
                c[13] = true;
            }
        }
        if(hua == 'H')
        {
            if (dian == '2' || dian == '3' || dian == '4' || dian == '5' || dian == '6' || dian == '7' || dian == '8' || dian == '9')
            {
                h[dian - '0'] = true;
            }
            if (dian == 'A')
            {
                h[1] = true;
            }
            if (dian == 'T')
            {
                h[10] = true;
            }
            if (dian == 'J')
            {
                h[11] = true;
            }
            if (dian == 'Q')
            {
                h[12] = true;
            }
            if (dian == 'K')
            {
                h[13] = true;
            }
        }
        if(hua == 'S')
        {
            if (dian == '2' || dian == '3' || dian == '4' || dian == '5' || dian == '6' || dian == '7' || dian == '8' || dian == '9')
            {
                s[dian - '0'] = true;
            }
            if (dian == 'A')
            {
                s[1] = true;
            }
            if (dian == 'T')
            {
                s[10] = true;
            }
            if (dian == 'J')
            {
                s[11] = true;
            }
            if (dian == 'Q')
            {
                s[12] = true;
            }
            if (dian == 'K')
            {
                s[13] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 13; i++)
    {
        if (!d[i]) cnt++;
    }
    for (int i = 1; i <= 13; i++)
    {
        if (!c[i]) cnt++;
    }
    for (int i = 1; i <= 13; i++)
    {
        if (!h[i]) cnt++;
    }
    for (int i = 1; i <= 13; i++)
    {
        if (!s[i]) cnt++;
    }
    cout << cnt;
    return 0;
}
