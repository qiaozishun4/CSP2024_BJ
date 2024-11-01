#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 100005

int n;
int r[MAXN], h[MAXN], ans;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> r[i];
        h[r[i]] ++;
    }

    ans = h[1];
    for(int i = 2; i <= 1e5; i ++)
    {
        ans = max(ans, h[i]);
    }

    cout << ans << endl;
    return 0;
}
