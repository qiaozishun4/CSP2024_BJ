#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
cin >> T;
    for(int k = 1;k<=T;k++)
    {
        int n, a[200005];
        cin >> n;
        for(int i = 1;i<=n;i++)
            cin >> a[i];
        cout << a[k] << endl;
    }
    return 0;
}
