#include <bits/stdc++.h>
using namespace std;
int b[10][20];
int val[256], typ[256];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    typ['D'] = 1;
    typ['C'] = 2;
    typ['H'] = 3;
    typ['S'] = 4;
    for(char i = '2';i <= '9';++i)
        val[i] = i - '0';
    val['A'] = 1;
    val['T'] = 10;
    val['J'] = 11;
    val['Q'] = 12;
    val['K'] = 13;
    int n;
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        b[typ[s[0]]][val[s[1]]]++;
    }
    int ans = 0;
    for(int i = 1;i <= 4;++i)
        for(int j = 1;j <= 13;++j)
            if(!b[i][j])
                ans++;
    cout << ans;
    return 0;
}

