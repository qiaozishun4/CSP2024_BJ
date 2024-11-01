#include <bits/stdc++.h>
using namespace std;

int a[15] = {0 , 0 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 0};

int main()
{
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);

    int n , cur = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) cout << a[i % 10 + 1] << endl;
    return 0;
}