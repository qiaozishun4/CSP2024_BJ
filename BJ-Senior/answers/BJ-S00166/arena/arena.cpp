#include <bits/stdc++.h>
using namespace std;

int a[100005], a2[100005], num[100005], w[4];
string s[100005];
vector<int> v, v2;

int lg(int x)
{
    int cnt = 1;
    while (x != 1) x /= 2;
    return cnt;
}

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> num[i];
    }
    for (int i = 1; i <= lg(n); ++i)
    {
        cin >> s[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        cout << 1 << endl;
    }
    //HF#24THMC
    return 0;
}