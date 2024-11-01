#include<bits/stdc++.h>
using namespace std;

int T, n;
int a[14] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> T;
    while(T--)
    {
        cin >> n;
        if(n <= 13)
        {
            cout << a[n] << endl;
            continue;
        }
        if(n%7 == 0 || n%7 == 2 || n%7 == 5 || n%7 == 6)
        {
            cout << a[n%7];
            int cnt = n/7;
            while(cnt--)
            {
                cout << '8';
            }
            cout << endl;
        }
        if(n%7 == 1 || n%7 == 3 || n%7 == 4)
        {
            cout << a[n%7+7];
            int cnt = n/7 - 1;
            while(cnt--)
            {
                cout << '8';
            }
            cout << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
