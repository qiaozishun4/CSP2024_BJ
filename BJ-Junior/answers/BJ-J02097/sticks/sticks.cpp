#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if(n % 7 == 1)
        {
            cout << 10;
            for(int i = 1;i * 7 + 8 <= n;i++) cout << 8;
        }
        if(n % 7 == 2)
        {
            cout << 1;
            for(int i = 1;i * 7 + 2 <= n;i++) cout << 8;
        }
        if(n % 7 == 3)
        {
            if(n == 3) cout << 7;
            if(n == 10) cout << 22;
            if(n > 10)
            {
                cout << 200;
                for(int i = 1;i * 7 + 17 <= n;i++) cout << 8;
            }
        }
        if(n % 7 == 4)
        {
            if(n == 4) cout << 4;
            else
            {
                cout << 20;
                for(int i = 1;i * 7 + 11 <= n;i++) cout << 8;
            }
        }
        if(n % 7 == 5)
        {
            cout << 2;
            for(int i = 1;i * 7 + 5 <= n;i++) cout << 8;
        }
        if(n % 7 == 6)
        {
            cout << 6;
            for(int i = 1;i * 7 + 6 <= n;i++) cout << 8;
        }
        if(n % 7 == 0)
        {
            for(int i = 1;i * 7 <= n;i++) cout << 8;
        }
        cout << endl;
    }
    return 0;
}
