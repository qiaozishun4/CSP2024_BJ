#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int a[200005];


int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        int ans = -1;
        for(int i = 0; i <= (1 << n) - 1; ++i)
//        for(int i = 101; i <= 101; ++i)
        {
            int cnt = 0;
            for(int j = 0, last0 = -1, last1 = -1; j < n; ++j)
            {
//                cout << a[j] << ":" << ((i >> j) & 1) << "*" << last0 << ":" << last1 << " ";
                if(((i >> j) & 1) == 0)
                {
                    if(a[j] == last0)
                        cnt += a[j];
                }
                else
                {
                    if(a[j] == last1)
                        cnt += a[j];
                }
                if(((i >> j) & 1) == 0)
                    last0 = a[j];
                else
                    last1 = a[j];
            }
//            cout <<endl;
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }


    return 0;
}
