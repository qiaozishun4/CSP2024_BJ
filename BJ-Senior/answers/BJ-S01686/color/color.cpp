#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int T;
int n;
int a[N];
int c[N];
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T -- )
    {
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int p = 0; p <= (1 << n) - 1; p ++)
        {
            int sum = 0;
            int s = p;
            for(int i = n; i >= 1; i --) 
            {
                c[i] = s % 2;
                s /= 2;
            }
            for(int i = 1; i <= n; i ++)
            {
                for(int j = i - 1; j >= 1; j -- )
                {
                    if(c[i] == c[j] && a[i] == a[j])
                    {
                        sum += a[j];
                    }
                }
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}