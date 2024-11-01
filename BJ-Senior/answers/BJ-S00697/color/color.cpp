#include <iostream>
using namespace std;

const int N = 30;
int n, a[N + 5];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        long long ans = 0;
        for (int i = 0; i < (1 << n); ++i)
        {
            int pre[2]{};
            long long res = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (pre[i >> j - 1 & 1] == a[j]) res += a[j];
                else pre[i >> j - 1 & 1] = a[j];
            }
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
    return 0;
}