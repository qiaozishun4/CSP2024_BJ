#include <bits/stdc++.h>//Finally, U Can Know China Computer Foundation
using namespace std;//孩子们！！！我要打表辣！！！！！！
int a[10];//幽 默 C C F
int qb[1124514];
signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    a[0] = 6;
    a[1] = 2;
    a[2] = 5;
    a[3] = 5;
    a[4] = 3;
    a[5] = 5;
    a[6] = 6;
    a[7] = 3;
    a[8] = 7;
    a[9] = 6;
    memset(qb, -1,sizeof(qb));
    for (int i = 1; i <= 1145141; i ++)
        {
            //i = 10;
            int sum = a[i%10];
            bool flag = 0;
            if ((i % 1000000) / 100000)
            {
                sum += a[(i % 1000000) / 100000];
                flag = 1;
            }
            if ((i % 100000) / 10000 || flag)
            {
                sum += a[(i % 100000) / 10000];
                flag = 1;
            }
            if ((i % 10000) / 1000 || flag)
            {
                sum += a[(i % 10000) / 1000];
                flag = 1;
            }
            if ((i % 1000) / 100 || flag)
            {
                sum += a[(i % 1000) / 100];
                flag = 1;
            }if ((i % 100) / 10 || flag)
            {
                sum += a[(i % 100) / 10];
                flag = 1;
            }
            //cout << sum << endl;
            if (qb[sum] == -1)
            {

            qb[sum] = max(qb[sum], i);
            }
            else
            {
                qb[sum] = min(qb[sum], i);
            }


        }
    int t;
    cin >> t;
    for (; t; t --)
    {
        int n;
        cin >> n;
        //cout << n << ' ';
        if (n <= 43)
            cout << qb[n] << endl;
    }
    return 0;
}
