#include <iostream>
#include <cstring>
using namespace std;

int a[20010];
bool color[20010]; // false = red, true = blue;

int n, ans = -1;
int stas()
{
    int z = 0;
    for(int i = 2; i <= n; i++)
    {
		int c = 0;
        for(int j = i - 1; j; j--)
        {
			if(color[i] == color[j])
			{
				if(a[i] == a[j])
					c = a[i];
				break;
			}
		}
        z += c;
    }
    return z;
}

void dfs(int x)
{
    if(x > n)
    {
        ans = max(ans, stas());
        return;
    }
    color[x] = 1;
    dfs(x + 1);
    color[x] = 0;
    dfs(x + 1);
    return;
}
void solve()
{
    ans = -1;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1);
    cout << ans << endl;
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
