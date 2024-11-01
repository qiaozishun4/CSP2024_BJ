#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[10];

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        if(n == 1) cout << "-1\n";
        else if(n == 2) cout << "1\n";
        else if(n == 3) cout << "7\n";
        else if(n == 4) cout << "4\n";
        else if(n == 5) cout << "2\n";
        else if(n == 6) cout << "6\n";
        else if(n == 7) cout << "8\n";
        else if(n % 7 == 0)
        {
            for(int i = 1; i <= n / 7; i++)
                cout << "8";
            cout << "\n";
        }
        else if(n % 7 == 1)
        {
            cout << 10;
            for(int i = 1; i <= n / 7 - 1; i++)
                cout << "8";
            cout << "\n";
        }
        else if(n % 7 == 2)
        {
            cout << 1;
            for(int i = 1; i <= n / 7; i++)
                cout << "8";
            cout << "\n";
        }
        else if(n % 7 == 3)
        {
            cout << 40;
            for(int i = 1; i < n / 7; i++)
                cout << "8";
            cout << "\n";
        }
        else if(n % 7 == 4)
        {
            cout << 20;
            for(int i = 1; i < n / 7; i++)
                cout << "8";
            cout << "\n";
        }
        else if(n % 7 == 5)
        {
            cout << 2;
            for(int i = 1; i <= n / 7; i++)
                cout << "8";
            cout << "\n";
        }
        else if(n % 7 == 6)
        {
            cout << 6;
            for(int i = 1; i <= n / 7; i++)
                cout << "8";
            cout << "\n";
        }
    }
    return 0;
}
