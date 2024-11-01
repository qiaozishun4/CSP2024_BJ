#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
ll n, sum = 52;
string a[60];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    sum -= n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (i == n)
            {
                break;
            }
            if (a[i] == a[j])
            {
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}