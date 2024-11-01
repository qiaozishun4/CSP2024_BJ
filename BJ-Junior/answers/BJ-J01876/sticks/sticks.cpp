#include <iostream>
using namespace std;

int T, n;
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

struct bigint
{
    int a[128], c = 2;
    int size()
    {
        return a[0];
    }
    void plus1()
    {
        c = 0;
        a[1]++;
        for (int i = 1; i <= a[0]; i++)
        {
            if (a[i] > 9)
            {
                if (i == a[0]) a[0]++;
                a[i + 1] += a[i] / 10;
                a[i] %= 10;
            }
            c += cost[a[i]];
        }
    }
    void print()
    {
        for (int i = a[0]; i >= 1; i--) cout << a[i];
        cout << endl;
    }
};

int main()
{
    freoepn("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        bigint i;
        i.a[0] = i.a[1] = 1;
        bool flag = false;
        for (; i.size() <= 7; i.plus1())
        {
            if (i.c == n)
            {
                i.print();
                flag = true;
                break;
            }
        }
        if (!flag) cout << -1 << endl;
    }
    return 0;
}