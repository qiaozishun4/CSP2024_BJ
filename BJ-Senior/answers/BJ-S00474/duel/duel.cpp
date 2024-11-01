#include <bits/stdc++.h>
using namespace std;

int n, a[100005], attack[100005], allive[100005], num[100005], cur, ans;

int read()
{
    int f = 1, ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = ret * 10 + (ch - '0');
        ch = getchar();
    }
    return ret * f;
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        if (!attack[a[i]]) num[++cur] = a[i];
        attack[a[i]]++;
        allive[a[i]]++;
    }
    sort(num + 1, num + cur + 1);
    for (int i = 1; i <= cur; i++)
    {
        for (int j = i + 1; j <= cur; j++)
        {
            if (allive[num[i]] <= attack[num[j]])
            {
                allive[num[i]] = 0;
                attack[num[j]] -= allive[num[i]];
            }
            else
            {
                allive[num[i]] -= attack[num[j]];
                attack[num[j]] = 0;
            }
        }
    }
    for (int i = 1; i <= cur; i++)
        ans += allive[num[i]];
    cout << ans << endl;
    return 0;
}
