#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[1000005];
priority_queue<int> q;
priority_queue<int> qq;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1, a+n+1);
    long long x = 1, ans = n, one = 1, two = 0, ct = 1;
    q.push(a[1]);
    for (int i = 2;i <= n;i++)
    {
        if (a[i] == 1) one++;
        else two++;
        if (x > 0 && a[i] != q.top())
        {
            q.pop();
            x--;
            ans--;
            qq.push(a[i]);
        }
        else if (x > 0 && a[i] == q.top())
        {
            x++;
            q.push(a[i]);
        }
        else if (x == 0 && a[i] > qq.top())
        {
            qq.pop();
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
