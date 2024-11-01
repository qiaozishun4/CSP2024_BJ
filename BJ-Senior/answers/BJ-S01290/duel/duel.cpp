#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int r[N];
bool broken[N], used[N];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    sort(r + 1, r + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (broken[i]) continue;
        for (int j = i + 1; j <= n; j++)
        {
            if (r[i] < r[j] && !used[j])
            {
                //cout << i << '<' << j << endl;
                used[j] = true;
                broken[i] = true;
                //cout << used[j] << ' ' << broken[i] << endl;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += !(broken[i]);
        //if (!broken[i]) cout << i << ':' << r[i] << ' ';
    }
    printf("%d", ans);
    return 0;
}
