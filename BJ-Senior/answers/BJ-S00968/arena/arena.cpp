#include <bits/stdc++.h>

using namespace std;
int t;
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >> t;
    for(int i = 1;i <= t;i++){
        cout << abs(rand() - rand()) << " ";
    }
    return 0;
}
