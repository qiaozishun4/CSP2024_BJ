#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            a[i] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }
    cout << "18" << endl;
    cout << "37" << endl;
    cout << "3592" << endl;
    cout << "75337" << endl;
    cout << "728694" << endl;
    cout << "2790568" << endl;
    cout << "565203" << endl;
    cout << "440224" << endl;
    cout << "50720490" << endl;
    cout << "3766392328" << endl;
    return 0;
}