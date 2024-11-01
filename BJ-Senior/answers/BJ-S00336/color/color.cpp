#include<iostream>
#include<cstdio>
using namespace std;

int t, n, a[100005];
long long ans;

void dfs(int step, int red, int blue, long long cnt)
{
    if(step > n)
    {
        ans = max(ans, cnt);
        return;
    }

    dfs(step + 1, step, blue, cnt + (a[red] == a[step]) * a[step]);

    dfs(step + 1, red, step, cnt + (a[blue] == a[step]) * a[step]);
}

int main()
{
    freopen("color2.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> t;
    while(t --)
    {
        cin >> n;
        for(int i = 1; i <= n; i ++)
            cin >> a[i];

        dfs(1, 0, 0, 0);

        cout << ans << endl;

        ans = 0;
    }

    return 0;
}
