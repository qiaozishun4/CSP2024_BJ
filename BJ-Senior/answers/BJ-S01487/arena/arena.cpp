#include <bits/stdc++.h>
using namespace std;

int a[10010] , j[10010];

int main()
{
    freopen("arean.in" , "r" , stdin);
    freopen("arean.out" , "w" , stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n ， sum = 0;
        cin >> n;
        for (int i = 1;i <= n;i++)
            cin >> a[i];
        for (int i = 1;i <= n;i++)
        {
            cin >> j[i];
            sum += j[i];
        }
        cout << sum << endl;
    }
    return 0;
}
