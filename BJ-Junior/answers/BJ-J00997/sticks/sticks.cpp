#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int t;
    cin >> t;

    for(int as = 0; as < t; as++)
    {
        int n;
        cin >> n;
        if(n == 1)
            cout << -1 << endl;
        else if(n == 2)
            cout << 1 << endl;
        else if(n == 3)
            cout << 7 << endl;
        else if(n == 4)
            cout << 4 << endl;
        else if(n == 5)
            cout << 2 << endl;
        else if(n == 6)
            cout << 6 << endl;
        else if(n == 10)
            cout << 22 << endl;
        else
        {
            int x = n/7;
            int y = n%7;
            if(y == 0)
            {
                for(int i = 0; i < x; i++)
                    cout << 8;
                cout << endl;
            }
            else if(y == 1)
            {
                cout << 10;
                for(int i = 0; i < x-1; i++)
                    cout << 8;
                cout << endl;
            }
            else if(y == 2)
            {
                cout << 1;
                for(int i = 0; i < x; i++)
                    cout << 8;
                cout << endl;
            }
            else if(y == 3)
            {
                cout << 200;
                for(int i = 0; i < x-2; i++)
                    cout << 8;
                cout << endl;
            }
            else if(y == 4)
            {
                cout << 20;
                for(int i = 0; i < x-1; i++)
                    cout << 8;
                cout << endl;
            }
            else if(y == 5)
            {
                cout << 2;
                for(int i = 0; i < x; i++)
                    cout << 8;
                cout << endl;
            }
            else if(y == 6)
            {
                cout << 6;
                for(int i = 0; i < x; i++)
                    cout << 8;
                cout << endl;
            }
        }

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
