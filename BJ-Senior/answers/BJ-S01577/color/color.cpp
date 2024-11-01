#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long sum;
int a[N], s[N];

void solve(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (s[i] > 1 && s[i] % 2 != 0)
        {
            sum += s[i] * a[i];
        }
    }
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            s[a[i]]++;
        }
        solve(n);
        printf("%d\n", sum);
    }
    return 0;
}