#include <bits/stdc++.h>
using namespace std;

string str[55];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        bool flag = true;
        for (int j = 1; j <= ans; j++)
        {
            if (s == str[j])
            {
                flag = false;
                break;
            }
        }
        if (flag) str[++ans] = s;
    }
    cout << 52 - ans << endl;
    return 0;
}
