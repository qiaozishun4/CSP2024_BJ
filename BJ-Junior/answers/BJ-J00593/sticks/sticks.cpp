#include <iostream>
#include <cstdio>
using namespace std;

int c[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[100005], flag = 1;

void dfs(int id, int cnt, int m, int n)
{
    if (id > m)
    {
        if (cnt == n && flag)
        {
            flag = 0;
            return ;
        }
    }
    if (!flag)
        return ;
    if (cnt + (m - id + 1) * 7 < n)
        return ;
    if (cnt + 2 > n)
        return ;
    for (int i = 0; i <= 9; i++)
    {
        if (id == 1 && i == 0)
            continue;
        a[id] = i;
        dfs(id + 1, cnt + c[i], m, n);
        if (!flag)
            return ;
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 1)
        {
            cout << "-1\n";
        }
        else if (n % 7 == 0)
        {
            while (n)
                cout << 8, n -= 7;
            cout << endl;
        }
        else if (n % 7 == 1)
        {
            cout << 16;
            n -= 8;
            while (n)
                cout << 8, n -= 7;
            cout << endl;
        }
        else
        {
            int mt = -1;
            for (int i = 1; 2 * i <= n; i++)
            {
                flag = 1;
                dfs(1, 0, i, n);
                if (a[1] != 0 && !flag)
                {
                    mt = i;
                    break;
                }
            }
            if (a[1] == 0 && flag)
                cout << "-1\n";
            else
            {
                for (int i = 1; i <= mt; i++)
                    cout << a[i];
                cout << endl;
            }
        }
    }
    return 0;
}
