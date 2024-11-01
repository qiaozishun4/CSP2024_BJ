#include <iostream>
#include <cstring>
using namespace std;
int a[200005], sum = 0, maxx = 0;
int ans[200005]; // blue 1 / red 0
int check[1000005], box[1000005];

void dfs(int l, int r)
{
    memset(box, 0, sizeof(box));
    if (l >= r) return ;
    if (a[l] != a[r] && l == r + 1) return ;
    int maxn = -1, x = -1, y = -1;
    x = 1;
    maxx = -1;
    for (int i = l;i <= r;i++)
    {
        box[a[i]]++;
        maxx = max(maxx, a[i]);
    }
    for (int k = 1;k <= maxx;k++)
    {
        if (box[k] >= 2)
        {
            x = 1;
            for (int i = l;i <= r;i++)
            {
                if (a[i] == k)
                {
                    //cout << k << " " << x << "~" << i - 1 << endl;
                    dfs(x, i - 1);
                    ans[i] = 1;
                    x = i + 1;
                }
            }
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
        bool ko = true;
        memset(check, 0, sizeof(check));
        memset(ans, 0, sizeof(ans));
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i];
            if (check[a[i]] > 0)
            {
                ko = false;
            }
            check[a[i]]++;
        }
        if (ko)
        {
            cout << 0 << endl;
            continue;
        }
        sum = 0;
        dfs(1, n);
        int bm = 0, rm = 0;
        for (int i = 1;i <= n;i++)
        {
            if (ans[i] == 1)
            {
                if (a[i] == bm) sum += a[i];
                bm = a[i];
            }
            else
            {
                if (a[i] == rm) sum += a[i];
                rm = a[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
