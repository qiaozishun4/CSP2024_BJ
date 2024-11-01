#include <bits/stdc++.h>
using namespace std;
long long n, num=0, cnt=0;
string s1, s2[100];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        bool b=true;
        cin >> s1;
        for (int j = 1; j <= cnt; j++)
        {
            if (s1 == s2[j])
            {
                b = false;
                break;
            }
        }
        if (b == 1)
        {
            s2[++cnt] = s1;
            num++;
        }
    }
    cout << 52-num;
    return 0;
}
