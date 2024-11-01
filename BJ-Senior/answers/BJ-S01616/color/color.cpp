#include <iostream>
using namespace std;

const int nr = 2e5 + 5;
int T, n, ans;
int a[nr];
bool w[nr];

void dfs(int step)
{
    if (step > n)
    {
        int last1 = 0, last2 = 0, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (w[i] == 0)
            {
                if (last1 == a[i])
                {
                    sum += a[i];
                }
                last1 = a[i];
            }
            else
            {
                if (last2 == a[i])
                {
                    sum += a[i];
                }
                last2 = a[i];
            }
        }
        ans = max(ans, sum);
        return;
    }
    w[step] = 0;
    dfs(step + 1);
    w[step] = 1;
    dfs(step + 1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ans = 0;
        dfs(2);
        cout << ans << "\n";
    }
    return 0;
}
