#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n % 7 == 0)
        {
            for(int i=0;i<n/7;i++) cout << 8;
        }
        else cout << -1;
        cout << endl;
    }
    return 0;
}
