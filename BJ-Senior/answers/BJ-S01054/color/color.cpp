#include<iostream>


using namespace std;

const int N = 2010;
int n;
int a[N], col[N];
int ans = 0;

void dfs(int x)
{
    if(x > n)
    {
        int scr = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i - 1; j >= 1; j--)
                if(col[i] == col[j])
                {
                    scr += a[i] * (a[i] == a[j]);
                    break;
                }
        ans = max(ans, scr);
        return;
    }
    col[x] = 0;
    dfs(x + 1);
    col[x] = 1;
    dfs(x + 1);
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
