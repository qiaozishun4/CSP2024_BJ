#include <iostream>
#include <string>
#include <map>
using namespace std;

int a[1005][2005];

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >>m >>k;
        for (int i = 1; i <= n; i++)
        {
            int l;
            cin >> l;
            a[i][0] = l;
            for (int j = 1; j <= l; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= k; i++)
        {
            int r, c;
            cin >> r >> c;
            bool flag = true;
            for (int j = 1; j <= n; j++)
            {
                for (int q = 1; q <= a[j][0]; q++)
                {
                    if (a[j][q] == 1 && a[j][q + 1] == c)
                    {
                        cout << "1" << endl;
                        flag = false;
                        break;
                    }
                }
                if (!flag)break;
            }
            if (flag)
            {
                cout << "0" << endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
