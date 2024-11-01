#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool f[4][13];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        char a = s[0];
        char b = s[1];
        int idx1 = 4, idx2 = 13;
        switch(a)
        {
            case 'D': idx1 = 0; break;
            case 'C': idx1 = 1; break;
            case 'H': idx1 = 2; break;
            case 'S': idx1 = 3; break;
        }
        switch(b)
        {
            case 'A': idx2 = 0; break;
            case 'T': idx2 = 9; break;
            case 'J': idx2 = 10; break;
            case 'Q': idx2 = 11; break;
            case 'K': idx2 = 12; break;
            default : idx2 = b - '1'; break;
        }
        f[idx1][idx2] = 1;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            if (!f[i][j])
                ans++;
    cout << ans;
    return 0;
}
