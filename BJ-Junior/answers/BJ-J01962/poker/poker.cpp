#include <iostream>
using namespace std;

bool a[200][200];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    memset(a, false, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s[1] == "A") a[s[0]][1] = true;
        else if (s[1] == "T") a[s[0]][10] = true;
        else if (s[1] == "J") a[s[0]][11] = true;
        else if (s[1] == "Q") a[s[0]][12] = true;
        else if (s[1] == "K") a[s[0]][13] = true;
        else a[s[0]][s[1]-'0'] = true;
    }
    int d = "D", c = "C", h = "H", s = "S", ans = 0;
    for (int i = 1; i <= 13; i++)
    {
        if (!a[d][i] || !a[c][i] || !a[h][i] || !a[s][i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}