#include<bits/stdc++.h>
using namespace std;
const int N = 10, M = 15;
bool cnt[N][M];
string s;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int f = 0;
        cin >> s;
        if(s[1] == 'A')
            f = 1;
        else if('2' <= s[1] && s[1] <= '9')
            f = s[1] - '0';
        else if(s[1] == 'T')
            f = 10;
        else if(s[1] == 'J')
            f = 11;
        else if(s[1] == 'Q')
            f = 12;
        else if(s[1] == 'K')
            f = 13;
        if(s[0] == 'D')
            cnt[1][f] = true;
        else if(s[0] == 'C')
            cnt[2][f] = true;
        else if(s[0] == 'H')
            cnt[3][f] = true;
        else if(s[0] == 'S')
            cnt[4][f] = true;
    }
    int cnt1 = 0;
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 13;j++)
            cnt1 += cnt[i][j];
    }
    cnt1 = 52 - cnt1;
    cout << cnt1 << endl;
    return 0;
}