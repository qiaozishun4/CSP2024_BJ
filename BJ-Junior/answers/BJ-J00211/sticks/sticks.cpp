#include <bits/stdc++.h>
using namespace std;
int c[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, t;
int cal(int x)
{
    int ans = 0, t = x;
    while(t > 0)
    {
        ans += c[t % 10];
        t /= 10;
    }
    return ans;
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &n);
    int ans = 0;
    while (n--)
    {
        cin >> t;
        if (t <= 1) {cout<<"-1"<<endl;continue;}
        if (t % 7 == 0)
        {
            for (int i = 1; i <= t / 7; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        if (t % 7 == 1)
        {
            cout << 10;
            for (int i = 1; i <= t / 7-1; i++)
                cout << 8;
            cout << endl;
            continue;
        }
        for (int i = 0; ; i++)
            if (cal(i) == t)
            {
                cout << i << endl;
                break;
            }

    }
    return 0;
}
