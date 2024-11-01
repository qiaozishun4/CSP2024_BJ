#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int r[100010];
int vis[100010];
int death[100010];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    sort(r + 1, r + n + 1);
    int ptr = 1, ans = n;
    for (int i = 1; i <= n; i++)
    {
        if (ptr >= i)
            continue;
        if (r[ptr] == r[i])
            continue;
        ptr++;
        ans--;
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
