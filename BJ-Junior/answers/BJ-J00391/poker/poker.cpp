#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, sum = 0;
    string s[55];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i] == s[j])
            {
                sum++;
            }
        }
    }
    cout << 52 - n + sum;
    return 0;
}