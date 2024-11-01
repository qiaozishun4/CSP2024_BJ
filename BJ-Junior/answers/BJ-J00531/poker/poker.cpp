#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
bool a[10][15];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'D')
        {
            s[0] = '1';
        }
        else if (s[0] == 'C')
        {
            s[0] = '2';
        }
        else if (s[0] == 'H')
        {
            s[0] = '3';
        }
        else
        {
            s[0] = '4';
        }
        if (s[1] == 'T')
        {
            a[s[0] - '0'][10]++;
            continue;
        }
        if (s[1] == 'J')
        {
            a[s[0] - '0'][11]++;
            continue;
        }
        if (s[1] == 'Q')
        {
            a[s[0] - '0'][12]++;
            continue;
        }
        if (s[1] == 'K')
        {
            a[s[0] - '0'][13]++;
            continue;
        }
        if (s[1] == 'A')
        {
            a[s[0] - '0'][1]++;
            continue;
        }
        a[s[0] - '0'][s[1] - '0']++;
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (a[i][j] == false)
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
