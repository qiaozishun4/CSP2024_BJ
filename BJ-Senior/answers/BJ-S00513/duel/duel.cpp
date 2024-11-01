#include <iostream>
#include <stdio.h>
using namespace std;

int a[100010];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int i = 1;
    for (int j = 2; j <= 100000; j++)
    {
        if (a[j] > 0)
        {
            if (a[i] <= a[j])
            {
                n -= a[i];
                a[j] -= a[i];
                i = j;
            }
            else
            {
                n -= a[j];
            }
        }
    }
    cout << n;
    return 0;
}