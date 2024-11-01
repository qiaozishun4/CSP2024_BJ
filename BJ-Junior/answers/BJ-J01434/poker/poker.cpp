#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    long long cnt = 52;
    string sets[60];
    long long pos = 0;
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        bool flag = 1;
        for (int j = 0; j < pos; j++)
        {
            if (sets[j] == s)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            sets[pos] = s;
            pos++;
            cnt--;
        }
    }
    cout << cnt;
    return 0;
}
