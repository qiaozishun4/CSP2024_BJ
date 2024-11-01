#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 2e5 + 5;
int a[maxN], c[maxN];

enum
{
    Red = 0,
    Blue = 1
};

int n, ans;
void dfs(int pos)
{
    if(pos == n + 1)
    {
        int sum = 0;
        for(int i = 2; i <= n;i++)
        {
            for(int j = i- 1; j >= 1; j--)
            {
                if(c[i] == c[j])
                {
                    if(a[i] == a[j])
                    {
                        sum += a[i];
                    }
                    break;
                }
            }
        }
        ans = max(ans, sum);
        return;
    }

    c[pos] = Red;
    dfs(pos + 1);
    c[pos] = Blue;
    dfs(pos + 1);
}

signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n;
        set<int> st;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            st.insert(a[i]);
        }

        if((int)st.size() == n)
        {
            cout << "0\n";
            continue;
        }

        dfs(1);
        cout << ans << '\n';
    }//while
    return 0;
}
