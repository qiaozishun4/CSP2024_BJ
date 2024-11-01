#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[14] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, p, k;
        cin >> n;
        if (n == 0 || n == 1)
        {
            cout <<-1 << endl;
            continue;
        }
        k = n / 7;
        p = n % 7;
        if (k > 0)
        {
            k--;
            p += 7;
        }
        /*if (n % 7 == 0) k = n / 7 - 1, p = 8;
        if (n % 7 == 1) k = n / 7 - 1, p = 10;
        if (n % 7 == 2) k = n / 7, p = 1;
        if (n % 7 == 3) k = n / 7, p = 7;
        if (n % 7 == 4) k = n / 7, p = 4;
        if (n % 7 == 5) k = n / 7, p = 2;
        if (n % 7 == 6) k = n / 7, p = 6;*/
        printf("%d", a[p]);
        for (int i = 1; i <= k; i++)
        {
            printf("8");
        }
        printf("\n");
    }
    return 0;
}
