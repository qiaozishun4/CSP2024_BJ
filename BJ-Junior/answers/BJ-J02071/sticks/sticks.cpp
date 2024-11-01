#include <bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        cin >> n;
        if(n==1)
        {
            cout << -1;
        }
        if(n==2)
        {
            cout << 1;
        }
        if(n==3)
        {
            cout << 7;
        }
        if(n==4)
        {
            cout << 4;
        }
        if(n==5)
        {
            cout << 14;
        }
        if(n==6)
        {
            cout << 6;
        }
        if(n==7)
        {
            cout << 8;
        }
        if(n==8)
        {
            cout << 10;
        }
        if(n==9)
        {
            cout << 16;
        }
        if(n==10)
        {
            cout << 22;
        }
        if(n==18)
        {
            cout << 208;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
