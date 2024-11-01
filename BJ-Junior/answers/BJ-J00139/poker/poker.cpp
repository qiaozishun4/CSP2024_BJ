#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, ans;
string s[55], a = "DCHS", b = "A23456789TJQK";
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (a[i] == s[k][0] && b[j] == s[k][1])
                {
                    ans--;
                    break;
                }
            }
            ans++;
        }
    }
    cout << ans;
    return 0;
}
