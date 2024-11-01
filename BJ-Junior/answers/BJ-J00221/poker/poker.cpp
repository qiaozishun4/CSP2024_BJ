# include <bits/stdc++.h>
using namespace std;

 const int MAXN = 52 + 7;
 string s[MAXN];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 52;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        bool flag = true;
        for (int j = 1; j <= i-1; j++)
        {
            if (s[i] == s[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans --;
    }
    cout << ans << endl;
    return 0;
}
