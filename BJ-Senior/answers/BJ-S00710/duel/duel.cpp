#include <iostream>
#include <algorithm>
using namespace std;

const int NR = 1e5 + 10;
int a[NR], box[NR];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int lst = a[1], cur = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == lst) cnt++;
        if (a[i] != lst)
        {
            box[++cur] = cnt;
            lst = a[i], cnt = 1;
        }
    }
    box[++cur] = cnt;
    int k = 1;
    for (int i = 2; i <= cur; i++)
    {
        int crt = box[i];
        while (crt >= box[k] && k < i)
        {
            crt -= box[k], box[k] = 0;
            k++;
        }
        if (k < i) box[k] -= crt;
    }
    int ans = 0;
    for (int i = 1; i <= cur; i++) ans += box[i];
    cout << ans << '\n';
    return 0;
}
