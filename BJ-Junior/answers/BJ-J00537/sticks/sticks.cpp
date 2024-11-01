#include <bits/stdc++.h>
using namespace std;

int t;
int a[11] = {6,2,5,5,4,5,6,3,7,6};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    for(int k = 1;k <= t;k++)
    {
        int n;
        cin >> n;
        int high =-114514;
        int lowhigh = -114514;
        int eight = 0;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if(n == 2)
        {
            cout << 1 << endl;
            continue;
        }
        if(n == 3)
        {
            cout << 7 << endl;
            continue;
        }
        if(n == 4)
        {
            cout << 4 << endl;
            continue;
        }
        if(n == 5)
        {
            cout << 2 << endl;
            continue;
        }
        if(n == 6)
        {
            cout << 6 << endl;
            continue;
        }
        while(n >= 7)
        {
            eight++;
            n -= 7;
        }
        if(n == 0)
        {
            for(int i = 1;i <= eight;i++)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if(n == 6)
        {
            high = 6;
        }
        if(n == 2)
        {
            high = 1;
        }
        if(n == 5)
        {
            high = 2;
        }
        if(n == 4)
        {
            high = 2;
            lowhigh = 0;
        }
        if(n == 1)
        {
            lowhigh = 0;
            high = 1;
        }
        if(n == 3)
        {
            lowhigh = 0;
            high = 4;
        }
        cout << high;
        if(lowhigh != -114514)
        {
            cout << lowhigh;
            eight--;
        }
        for(int i = 1;i <= eight;i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}
