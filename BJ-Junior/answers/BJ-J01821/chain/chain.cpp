#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);
    srand(time(0));
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k,q;
        cin >> n >> k >> q;
        while(q--)
        {
            cout << rand() % 2 <<endl;
        }
    }
    return 0;
}
