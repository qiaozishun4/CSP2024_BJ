#include <bits/stdc++.h>
using namespace std;

bool vis[128][128] = {};
int n,cnt = 0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        if (vis[s[0]][s[1]] == false)
        {
            cnt++;
            vis[s[0]][s[1]] = true;
        }
    }
    cout << 52 - cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
