#include <bits/stdc++.h>
using namespace std;
int cnt[17] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int T, n;
bool flag = false;
string ans;
string cmp(string a, string b)
{
    if (a.length() > b.length())
        return b;
    else if (a.length() < b.length())
        return a;
    else if (a > b)
        return b;
    else if (a < b)
        return a;
}
void dfs(int step, int s, string t)
{
    if (flag == true && (t.length() > ans.length() || (t.length() == ans.length() && t > ans)))
        return;
    if (s == 0)
    {
        if (flag == false)
            ans = t;
        else
            ans = cmp(ans, t);
        flag = true;
        return;
    }

    int i = 0;
    if (step == 1)
        i++;
    for (i; i <= 9; i++)
    {
        if (s - cnt[i] >= 0)
            dfs(step + 1, s - cnt[i], t + (char)(i + '0'));
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while (T--)
    {
        flag = false;
        cin >> n;
        dfs(1, n, "");
        if (flag == false)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
