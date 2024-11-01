#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[1000005];
priority_queue<int, vector<int>, greater<int> > q;
signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (q.empty())
        {
            q.push(a[i]);
        }
        else
        {
            if (q.top() >= a[i])
            {
                q.push(a[i]);
            }
            else
            {
                q.pop();
                q.push(a[i]);
            }
        }
    }
    cout << q.size();
    return 0;
}
