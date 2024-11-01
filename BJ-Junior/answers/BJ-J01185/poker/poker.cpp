#include <iostream>
using namespace std;
bool vis[4][13];
int n, aa, bb, cnt;
string s;
string a, b;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    a = "DCHS";
    b = "A23456789TJQK";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < 4; j++)
            if (a[j] == s[0])
                aa = j;
        for (int j = 0; j < 13; j++)
            if (b[j] == s[1])
                bb = j;
        vis[aa][bb] = true;
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            if (!vis[i][j])
                cnt++;
    cout << cnt << endl;
    return 0;
}
