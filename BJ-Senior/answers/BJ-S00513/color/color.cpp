#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int a[200010];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof a );
        int n, cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (a[x]) cnt += x;
            a[x]++;
        }
        cout << cnt << endl;
    }
    return 0;
}