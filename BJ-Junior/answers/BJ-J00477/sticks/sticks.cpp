#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n % 7 == 0) 
            for (int i = 1; i <= n / 7; i++) putchar('8');
        else 
        {
            putchar('1'), putchar('0');
            for (int i = 1; i < n / 7; i++) putchar('8');
        }
        putchar('\n');
    }
    return 0;
}