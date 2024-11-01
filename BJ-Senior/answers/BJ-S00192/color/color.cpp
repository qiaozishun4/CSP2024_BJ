#include<bits/stdc++.h>

using namespace std;

int n, a[20], col[20], ans;

void dfs(int step)
{
    if(step > n)
    {
        int sum = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i - 1; j >= 1; j--)
                if(col[i] == col[j] && a[i] == a[j])
                {
                    sum += a[i];
                    break;
                }
        ans = max(ans, sum);
        return;
    }
    col[step] = 0;
    dfs(step + 1);
    col[step] = 1;
    dfs(step + 1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
