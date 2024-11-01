#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T, n, k, p;
    char a[10000010];
    cin << T << n << k << p << a[10000010];
    for(int i = 1; i <= n; i++)
    {
        if(a[n] == a[n-1])
            cout << "0";
        if(a[n] == a[n+1])
            cou << "0"
        else
            cout << "1";
    }
    return 0;
}