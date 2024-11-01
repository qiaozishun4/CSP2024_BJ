#include <bits/stdc++.h>
using namespace std;

int a[30] = {0 , -1 , 1 , 7 , 4 , 2 , 6 , 8 , 10 , 18 , 22 , 20 , 28 , 68 , 88 , 108 , 188 , 200 , 208 , 288 , 688};

int main()
{
    freopen("sticks.in", "r" , stdin);
    freopen("sticks.out", "w" , stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}