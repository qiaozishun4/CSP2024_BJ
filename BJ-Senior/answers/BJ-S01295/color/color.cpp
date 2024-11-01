#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, ans;
int a[N], col[N];
int dfs(int i)
{
    if (i > n)
    {
        int lst[3] = {0, 0, 0};
        int res = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (a[i] == lst[col[i]]) res += a[i];
            lst[col[i]] = a[i];
        }
        return res;
    }
    col[i] = 1;
    int tmp = dfs(i + 1);
    col[i] = 2;
    return max(tmp, dfs(i + 1));
}
int main(){
    freopen("color.in","r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T --)
    {
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        cout << dfs(1) << "\n";
    }

    return 0;
}
