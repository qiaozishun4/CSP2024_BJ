#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;
map <string, bool> mp;
char az[4] = {'D', 'C', 'H', 'S'}, bz[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

int main ()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    int i, j;
    int ancs = 0;
    string a;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        mp[a] = true;
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 13; j++)
        {
            a = az[i];
            a += bz[j];
            if (!mp[a])
            {
                ancs++;
            }
        }
    }
    cout << ancs << endl;
    return 0;
}
