#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005];
int n;
int ans;

bool cmp(int x, int y)
{
    return x < y;
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    int min_pos;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[1])
        {
            min_pos++;
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
