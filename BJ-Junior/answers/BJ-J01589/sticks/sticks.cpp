#include <bits/stdc++.h>
using namespace std;
int a[100] = {0 , -1 , 1 , 7 , 4 , 5 , 6 , 8 , 10 , 18 , 22 , 20 , 28 , 68 , 88 , 108 , 188 , 200 , 208 , 288 , 688 , 888};// , 1088 , 1888 , 2008 , 2088 , 2888 , 6888 , 8888 , 10888 , 18888 , 20088 , 20888 , 28888 , 68888 , 88888 , 108888 , 188888 , 200888 , 208888 , 288888 , 688888 , 888888 , 1088888 , 1888888 , 2008888 , 2088888 , 2888888 , 6888888 , 8888888 , 10888888};
int main()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        if(n <= 20)
        {
            cout << a[n] << endl;
        }
        else
        {
            for(int i = 15; i <= 21; i++)
            {
                if((n - i) % 7 == 0)
                {
                    int y = (n - i) / 7;
                    cout << a[i];
                    for(int i = 1; i <= y; i++) cout << 8;
                    cout << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
