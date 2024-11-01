#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6;
int a[N + 5];
int n;

int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || '9' < ch)
    {
        if(ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while('0' <= ch && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch - 48);
        ch = getchar();
    }
    return x * f;
}

signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = read();
    while(t--)
    {
        n = read();
        for(int i = 1;i <= n;i++)
        {
            a[i] = read();
        }
        int ans = -9e18;
        for(int i = 0;i < (1 << (n - 1));i++)
        {
            int t = 0;
            for(int j = 2;j <= n;j++)
            {
                for(int k = j - 1;k >= 1;k--)
                {
                    if(((i >> (n - j)) & 1) == ((i >> (n - k)) & 1))
                    {
                        if(a[j] == a[k]) t += a[j];
                        break;
                    }
                }
            }
            ans = max(ans,t);
            //cout <<t << ' ' << ((i >> 2) & 1) << ' ' << ((i >> 1) & 1) << ' ' << (i & 1) << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
