#include <bits/stdc++.h>
using namespace std;

int st[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int t;
int min_n;

bool dfs(int num, int s)
{
    //init
    int tmp, i = 0;
    if (num == 0) i = 1;

    //keep searching or not
    if (s == 1) return false;
    else if (s == 0)
    {
        if (num <= min_n)
        {
            min_n = num;
            return true;
        }
        else return false;
    }
    //trying numbers
    for (;i < 10; i++)
    {
        if (s >= st[i])
        {
            bool flag = dfs(num * 10 + i, s - st[i]);
        }
    }
}

int main()
{
    freopen("sticks1.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int s0;
        cin >> s0;
        min_n = 0x7fffffff;
        dfs(0, s0);
        if (min_n != 0x7fffffff) cout << min_n << endl;
        else cout << -1 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
