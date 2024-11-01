#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define pii pair<int,int>
#define mp make_pair
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int n;
int a[N];
priority_queue<int> q;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) q.push(-a[i]);
    for (int i = 1; i <= n; i++)
    {
        int x = -q.top();
        if (a[i] > x) q.pop();
    }
    printf("%d\n", (int)q.size());
    return 0;
}