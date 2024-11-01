#include<bits/stdc++.h>
using namespace std;

// 1 -1, 2 1,3 7,4 4,5 2, 6 0 6,7 8

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        if(n <= 6)
        {
            if(n == 1)cout << -1 << endl;
            if(n == 2)cout << 1 << endl;
            if(n == 3)cout << 7 << endl;
            if(n == 4)cout << 4 << endl;
            if(n == 5)cout << 2 << endl;
            if(n == 6)cout << 6 << endl;
            continue;
        }
        int mo = n%7;
        if(mo == 0)
        {
            for(int i = 1; i <= n/7; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(mo == 1)
        {
            cout << 10;
            for(int i = 1; i <= (n-1)/7-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(mo == 2)
        {
            cout << 18;
            for(int i = 1; i <= (n-1)/7-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(mo == 3)
        {
            cout << 22;
            for(int i = 1; i <= (n-1)/7-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(mo == 4)
        {
            cout << 20;
            for(int i = 1; i <= (n-1)/7-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(mo == 5)
        {
            cout << 28;
            for(int i = 1; i <= (n-1)/7-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if(mo == 6)
        {
            cout << 68;
            for(int i = 1; i <= (n-1)/7-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
