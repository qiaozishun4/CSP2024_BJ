#include <bits/stdc++.h>
using namespace std;
int a[200010];
int b[1000010];
int main()
{
    freopen("color.in" , "r" , stdin);
    freopen("color.out" , "w" , stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 1 ; i <= n ; i ++)
        {
            cin >> a[i];
        }
        long long ans = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
            b[a[i]]++;
            if(b[a[i]] == 2)
            {
                ans += a[i];
                b[a[i]] = 0;
            }
        }
        for(int i = 1 ; i <= 1000000 ; i ++)
        {
            b[i] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
