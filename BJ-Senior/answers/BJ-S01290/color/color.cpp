#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5 + 5;
long long co[N], a[N], mx = -2e9;
void init()
{
    memset(co, 0, sizeof(co));
    memset(a, 0, sizeof(a));
    mx = -2e9;
}
long long calc(int n)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if (co[j] == co[i] && a[i] == a[j])
            {
                res += a[i];
                break;
            }
        }
    }
    return res;
}
void dfs(int cur, int n)
{
    if (cur > n)
    {
        int cl = calc(n);
        if (cl >= mx)
        {
            /*cout << cl << ":\n";
            for (int i = 1; i <= n; i++) cout << co[i] << " ";
            cout << endl;*/
            mx = cl;
        }
        return ;
    }
    co[cur] = 1;
    dfs(cur + 1, n);
    co[cur] = 0;
    co[cur] = 2;
    dfs(cur + 1, n);
    co[cur] = 0;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        init();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            //cout << a[i] << " ";
        }
        dfs(1, n);
        printf("%lld\n", mx);
    }
    return 0;
}
