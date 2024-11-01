#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N], p[N], n, max1 = -1;
bool ans[N];
void DFS(int x)
{
    //cout << x << '\n';
    if(x == n + 1)
    {
        int pos0 = -1, pos1 = -1;
        memset(p, 0, sizeof(p));
        for(int i = 1;i <= n;i++)
        {
            if(ans[i])
                p[i] = pos1, pos1 = i;
            else
                p[i] = pos0, pos0 = i;
        }
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            if(p[i] != -1 && a[i] == a[p[i]])
                sum += a[i];
        }
        max1 = max(max1, sum);
        return;
    }
    ans[x] = true;
    DFS(x + 1);
    ans[x] = false;
    DFS(x + 1);
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
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        max1 = -1;
        DFS(1);
        cout << max1 << '\n';
    }
    return 0;
}