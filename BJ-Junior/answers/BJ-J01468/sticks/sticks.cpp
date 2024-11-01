#include <iostream>
using namespace std;
int arr01[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int arr02[100004];
int findnum(int n)
{
    bool flag = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (arr01[i] == n)
        {
            return i;
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        return findnum(n-arr01[i]);
    }
}
void dfs(int n)
{
    for (int i = 1; i < 10; ++i)
    {
        int sticks = n-arr01[i];
        printf("%d", findnum(sticks));
    }
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        bool flag = 0;
        if (n==1 || n==3)
        {
            cout << -1 << endl;
            continue;
        }
        if (n <= 7)
        {
            for (int j = 1; j < 10; ++j)
            {
                if (arr01[j] == n)
                {
                    cout << j << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) continue;
        }
        if (flag == 0)
        {
            dfs(n);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
