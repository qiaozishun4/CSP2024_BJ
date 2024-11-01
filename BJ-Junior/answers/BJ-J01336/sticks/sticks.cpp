#include <iostream>
using namespace std;

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t --)
    {
        int n;
        cin >> n;
        bool flag = false;
        for (int i = 1; i <= 1e5; ++ i)
        {
            int x = i, cnt = 0;
            while (x)
            {
                cnt += num[x % 10];
                x /= 10;
            }
            if (cnt == n)
            {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}