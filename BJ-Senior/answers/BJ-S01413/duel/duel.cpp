#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int a[100010];
queue<int> q;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >>n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        q.push(a[i]);
        if (a[i] > q.front())
            q.pop();
    }
    cout << q.size() << endl;
    return 0;
}
