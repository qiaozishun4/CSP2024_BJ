#include <bits/stdc++.h>
using namespace std;
bool vis[2005];
int ini[100];
void init()
{
    ini['A'] = 1;
    ini['K'] = 13;
    ini['Q'] = 12;
    ini['J'] = 11;
    ini['T'] = 10;
    for(char i = '2'; i <= '9'; i++)
    {
        ini[i] = i - '0';
    }
}
int gethash(string t)
{
    int ans = 0;
    char k = t[0];
    if(k == 'S') ans += 0;
    else if(k == 'H') ans += 13;
    else if(k == 'D') ans += 26;
    else ans += 39;
    ans += ini[t[1]];
    return ans;
}
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    init();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        vis[gethash(s)] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= 52; i++)
    {
        if(vis[i] == 0) ans++;
    }
    cout << ans;
    return 0;
}
