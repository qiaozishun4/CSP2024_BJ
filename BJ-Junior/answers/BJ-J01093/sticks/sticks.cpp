#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n==1)
        {
            cout << -1 << endl;
            continue;
        }
        if (n==2)
        {
            cout << 1 << endl;
            continue;
        }
        if (n==3)
        {
            cout << 7 << endl;
            continue;
        }
        if (n==4)
        {
            cout << 4 << endl;
            continue;
        }
        if (n==5)
        {
            cout << 2 << endl;
            continue;
        }
        if (n==6)
        {
            cout << 6 << endl;
            continue;
        }
        if (n==7)
        {
            cout << 8 << endl;
            continue;
        }
        if (n==9)
        {
            cout << 18 << endl;
            continue;
        }
        if (n==10)
        {
            cout << 22 << endl;
            continue;
        }
        if (n==11)
        {
            cout << 20 << endl;
            continue;
        }
        if (n==12)
        {
            cout << 28 << endl;
            continue;
        }
        if (n==13)
        {
            cout << 80 << endl;
            continue;
        }
        if (n==16)
        {
            cout << 188 << endl;
            continue;
        }
        if (n==17)
        {
            cout << 200 << endl;
            continue;
        }
        if (n==18)
        {
            cout << 208 << endl;
            continue;
        }
        if (n==19)
        {
            cout << 288 << endl;
            continue;
        }
        if (n==20)
        {
            cout << 688 << endl;
            continue;
        }
        if (n%7==0)
        {
            int z=n/7;
            for (int i=1;i<=z;i++)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (n%7==1)
        {
            int z=n/7;
            cout << 1;
            for (int i=1;i<z;i++)
            {
                cout << 8;
            }
            cout << 0 << endl;
            continue;
        }
        if (n%7==2)
        {
            int z=n/7;
            cout << 1;
            for(int i=1;i<=z;i++)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if (n%7==5)
        {
            int z=n/7;
            cout << 2;
            for(int i=1;i<=z;i++)
            {
                cout << 8;
            }
            cout << endl;
            continue;
        }
    }
    return 0;
}
