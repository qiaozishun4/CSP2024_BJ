#include <bits/stdc++.h>

using namespace std;
int t;
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    for(int i = 1;i <= t;i++){
        cout << abs(rand() - rand()) << " ";
    }
    return 0;
}
