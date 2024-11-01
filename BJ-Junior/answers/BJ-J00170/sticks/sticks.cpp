#include <bits/stdc++.h>
using namespace std;

int sti[11]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int ans=1e9;
        if (x%7==0)
        {
            for (int i = 1; i <= x/7; i++)
            {
                cout << 8;
            }
        }
        cout << endl;
    }
    return 0;
}
// please give me a 30!! (this code is for sub 3, 4, 5)
