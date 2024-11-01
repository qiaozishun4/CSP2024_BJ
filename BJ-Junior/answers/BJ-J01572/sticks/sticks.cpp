#include<iostream>
using namespace std;

int n, a[5] = {0, -1, 1, 7, 4};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        if(x <= 4)
        {
            cout << a[x] << endl;
        }
        else if(x % 7 == 0)
        {
            for(int i = 1; i <= x / 7; i ++)
            {
                cout << '8';
            }
            cout << endl;
        }
        else if(x % 7 == 1)
        {
            cout << "10";
            for(int i = 1; i <= (x - 8) / 7; i ++)
            {
                cout << '8';
            }
            cout << endl;
        }
        else if(x % 7 == 2)
        {
            cout << "1";
            for(int i = 1; i <= (x - 2) / 7; i ++)
            {
                cout << '8';
            }
            cout << endl;
        }
        else if(x % 7 == 3)
        {
            cout << "22";
            for(int i = 1; i <= (x - 10) / 7; i ++)
            {
                cout << '8';
            }
            cout << endl;
        }
        else if(x % 7 == 4)
        {
            cout << "20";
            for(int i = 1; i <= (x - 11) / 7; i ++)
            {
                cout << '8';
            }
            cout << endl;
        }
        else if(x % 7 == 5)
        {
            cout << "2";
            for(int i = 1; i <= (x - 5) / 7; i ++)
            {
                cout << '8';
            }
            cout << endl;
        }
        else if(x % 7 == 6)
        {
            cout << "6";
            for(int i = 1; i <= (x - 6) / 7; i ++)
            {
                cout << '8';
            }
            cout << endl;
        }
    }

    return 0;
}