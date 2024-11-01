#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

*/
int d[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
stack <char> st;
signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    scanf("%lld", &t);
    while (t--)
    {
        int n;
        scanf("%lld", &n);
        if (n == 1)
        {
            puts("-1");
            continue;
        }
        while (n >= 14)
        {
            n -= 7;
            st.push('8');
        }
        if (n <= 7)
        {
            for (int i = 1; i <= 9; i++)
            {
                if (d[i] == n)
                {
                    st.push(i + '0');
                    break;
                }
            }
        }
        else
        {
            int x = 0x3f3f3f3f3f3f3f3f;
            for (int i = 1; i <= 9; i++)
            {
                for (int j = 0; j <= 9; j++)
                {
                    if (d[i] + d[j] == n)
                    {
                        x = min(x, i * 10 + j);
                    }
                }
            }
            printf("%lld", x);
        }
        while (!st.empty())
        {
            putchar(st.top());
            st.pop();
        }
        puts("");
    }
    return 0;
}