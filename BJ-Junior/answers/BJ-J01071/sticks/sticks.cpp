#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        if(n == 1)
            cout << -1;
        if(n == 2)
            cout << 1;
        if(n == 3)
            cout << 7;
        if(n == 4)
            cout << 4;
        if(n == 5)
            cout << 2;
        if(n == 6)
            cout << 6;
        if(n == 8)
            cout << 10;
        if(n == 9)
            cout << 18;
        if(n == 10)
            cout << 22;
        if(n == 11)
            cout << 26;
        if(n == 12)
            cout << 28;
        if(n == 13)
            cout << 68;
        if(n == 15)
            cout << 204;
        if(n == 16)
            cout << 202;
        if(n == 17)
            cout << 200;
        if(n == 18)
            cout << 208;
        if(n == 19)
            cout << 288;
        if(n == 20)
            cout << 688;
        if(n % 7 == 0)
        {
            for(int i = 1; i <= n; i +=7)
                cout << 8;
        }
        cout << endl;
    }
    return 0;
}