#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    srand(time(0));
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        while(k--)
            cout << rand()%2;
    }
return 0;
}