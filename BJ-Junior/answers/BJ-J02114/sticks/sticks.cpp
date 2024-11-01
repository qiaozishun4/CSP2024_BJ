#include <bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n/7;i++) cout << 8;
        cout << "\n";
    }
    return 0;
}


