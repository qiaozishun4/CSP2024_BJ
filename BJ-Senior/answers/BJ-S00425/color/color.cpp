#include <fstream>
using namespace std;

ifstream cin("color.in");
ofstream cout("color.out");
int n;
int a[200001];
int c[200001];
bool blue[200001];
int getans()
{
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int pos = i-1;
        while (pos > 0 && blue[pos] != blue[i]) pos--;
        if (pos == 0) continue;
        if (a[pos] == a[i])
            ans += a[i];
    }
    return ans;
}
int ans = 0;
int cnt = 0, hulf;
void dfs(int step)
{
    if (cnt == hulf) return;
    if (step > n) 
    {
        ans = max(ans, getans());
        cnt++;
        return;
    }
    blue[step] = true;
    dfs(step+1);
    blue[step] = false;
    dfs(step+1);
}
int power(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        cin >> n;
        hulf = power(2, n-1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dfs(1);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}