#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], c[N], n, max1 = -1;
vector <int> v;
void Ans()
{
    memset(c, 0, sizeof(c));
    int ans1 = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = i - 1;j >= 0;j--)
        {
            if(v[i] == v[j])
            {
                if(a[i + 1] == a[j + 1])
                    c[i] = a[i + 1];
                break;
            }
        }
        ans1 += c[i];
    }
    max1 = max(max1, ans1);
}
void Dfs(int x)
{
    if(x == n + 1)
    {
        Ans();
        return;
    }
    v.push_back(0);
    Dfs(x + 1);
    v.pop_back();
    v.push_back(1);
    Dfs(x + 1);
    v.pop_back();
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        max1 = -1;
        cin >> n;
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        Dfs(1);
        cout << max1 << endl;
    }
    return 0;
}