#include <bits/stdc++.h>
using namespace std;
string poker[53];
int n, sum;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.in", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> poker[i];
        sum++;
        if (i > 1)
        {
            for (int j = 1; j < i; j++)
            {
                if (poker[i] == poker[j])
                {
                    sum--;
                    break;
                }
            }
        }
    }
    if (52 - sum >= 0)
    {
        cout << 52 - sum;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
