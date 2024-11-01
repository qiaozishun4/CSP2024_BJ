#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);


    int t,a[10] = {6,2,5,5,4,5,6,3,7,6};
    cin >> t;

    while (t > 0)
    {
        t--;
        int n,d = -1;
        cin >> n;
        if (n % 7 == 0)
        {
            while (n > 0)
            {
                cout << 8;
                n -= 7;
            }
        }
        else if (n % 7 == 1)
        {
            cout << 10;
            n -= 8;
            while (n > 0)
            {
                cout << 8;
                n -= 7;
            }
        }
        else
        {
            for(int i = 1;i <= 1000000;i++)
            {
                int s = 0,x = i;
                while (x > 0)
                {
                    s += a[x % 10];
                    x /= 10;
                }
                if (s == n)
                {
                    d = i;
                    break;
                }
            }
            cout << d << endl;
        }

    }




    return 0;
}
