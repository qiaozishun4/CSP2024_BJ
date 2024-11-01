#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e3 + 5;
map<char, int> hs, ds;
bool have[N];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    hs['D'] = 1; hs['C'] = 2; hs['H'] = 3; hs['S'] = 4;
    ds['A'] = 1; ds['2'] = 2; ds['3'] = 3; ds['4'] = 4;
    ds['5'] = 5; ds['6'] = 6; ds['7'] = 7; ds['8'] = 8;
    ds['9'] = 9; ds['T'] = 10; ds['J'] = 11;
    ds['Q'] = 12; ds['K'] = 13;
    for (int i = 1; i <= n; i ++)
    {
        string s;
        cin >> s;
        int num = hs[s[0]] * 100 + ds[s[1]];
        have[num] = 1;
    }
    int cnt = 0;
    for (int col = 1; col <= 4; col ++)
        for (int dot = 1; dot <= 13; dot ++)
            if (!have[col * 100 + dot])
                cnt ++;
    cout << cnt;

    return 0;
}