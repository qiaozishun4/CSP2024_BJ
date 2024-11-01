#include <bits/stdc++.h>
using namespace std;
int n, a[15], b[15], c[15], d[15], sum;
string s;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if(s[0] == 'D')
        {
            if(s[1] == 'A')
            {
                a[1]=1;
            }
            else if(s[1] == 'T')
            {
                a[10]=1;
            }
            else if(s[1] == 'J')
            {
                a[11]=1;
            }
            else if(s[1] == 'Q')
            {
                a[12]=1;
            }
            else if(s[1] == 'K')
            {
                a[13]=1;
            }
            else
            {
                int q = s[1]-'0';
                a[q] = 1;
            }
        }
        else if(s[0] == 'C')
        {
            if(s[1] == 'A')
            {
                b[1]=1;
            }
            else if(s[1] == 'T')
            {
                b[10]=1;
            }
            else if(s[1] == 'J')
            {
                b[11]=1;
            }
            else if(s[1] == 'Q')
            {
                b[12]=1;
            }
            else if(s[1] == 'K')
            {
                b[13]=1;
            }
            else
            {
                int w = s[1]-'0';
                b[w] = 1;
            }
        }
        else if(s[0] == 'H')
        {
            if(s[1] == 'A')
            {
                c[1]=1;
            }
            else if(s[1] == 'T')
            {
                c[10]=1;
            }
            else if(s[1] == 'J')
            {
                c[11]=1;
            }
            else if(s[1] == 'Q')
            {
                c[12]=1;
            }
            else if(s[1] == 'K')
            {
                c[13]=1;
            }
            else
            {
                int e = s[1]-'0';
                c[e] = 1;
            }
        }
        else if(s[0] == 'S')
        {
            if(s[1] == 'A')
            {
                d[1]=1;
            }
            else if(s[1] == 'T')
            {
                d[10]=1;
            }
            else if(s[1] == 'J')
            {
                d[11]=1;
            }
            else if(s[1] == 'Q')
            {
                d[12]=1;
            }
            else if(s[1] == 'K')
            {
                d[13]=1;
            }
            else
            {
                int r = s[1]-'0';
                d[r] = 1;
            }
        }
    }
    for (int i = 1; i <= 13; i++)
    {
        if(a[i] == 0)
        {
            sum++;
        }
        if(b[i] == 0)
        {
            sum++;
        }
        if(c[i] == 0)
        {
            sum++;
        }
        if(d[i] == 0)
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
