#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5;
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
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n = read();
    for(int i = 1;i <= n;i++)
    {
        a[i] = read();
    }
    sort(a + 1,a + 1 + n);
    int head = 1;
    int ans = n;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] > a[head])
        {
            head++;
            ans--;
        }
    }
    cout << ans;
    return 0;
}
