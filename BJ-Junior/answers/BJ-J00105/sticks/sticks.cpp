#include<iostream>
using namespace std;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n <= 7)
        {
            if(n == 1) cout << -1;
            if(n == 2) cout << 1;
            if(n == 3) cout << 7;
            if(n == 4) cout << 4;
            if(n == 5) cout << 2;
            if(n == 6) cout << 6;
            if(n == 7) cout << 8;
        }
        else
        {
            if(n % 7 == 1)
            {
                cout << 10;
                for(int i = 1; i <= (n - 1) / 7 - 1; i++) cout << 8;
            }
            if(n % 7 == 2)
            {
                cout << 1;
                for(int i = 1; i <= (n - 2) / 7; i++) cout << 8;
            }
            if(n % 7 == 3)
            {
                cout << 200;
                for(int i = 1; i <= (n - 3) / 7 - 2; i++) cout << 8;
            }
            if(n % 7 == 4)
            {
                cout << 208;
                for(int i = 1; i <= (n - 4) / 7 - 2; i++) cout << 8;
            }
            if(n % 7 == 5)
            {
                cout << 288;
                for(int i = 1; i <= (n - 5) / 7 - 2; i++) cout << 8;
            }
            if(n % 7 == 6)
            {
                cout << 6;
                for(int i = 1; i <= (n - 6) / 7; i++) cout << 8;
            }
            if(n % 7 == 0)
            {
                for(int i = 1; i <= n / 7; i++) cout << 8;
            }

        }
        cout << endl;
    }

    return 0;
}
