#include <cstdio>
#include <iostream>
using namespace std;
int n,a[200005];
bool f[200005];
long long ans = 0;
void dfs(int p)
{
    if (p > n)
    {
        long long sum = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = i - 1;j >= 1;j--)
            {
                if (f[i] == f[j])
                {
                    if (a[i] == a[j]) sum += a[i];
                    break;
                }
            }
        }
        ans = max(ans,sum);
        return;
    }
    f[p] = 0;
    dfs(p + 1);
    f[p] = 1;
    dfs(p + 1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}