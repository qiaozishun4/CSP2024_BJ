#include<bits/stdc++.h>
using namespace std;
string s[60];
int cnt = 1;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 2; i <= n; i++)
    {
        bool flag = 0;
        for (int j = 1; j < i; j++)
        {
            if (s[i]== s[j]) flag = 1;
        }
        if (flag == 0) cnt++;
    }
    if (52-cnt < 0) cout << 0;
    else cout << 52 - cnt;
}
