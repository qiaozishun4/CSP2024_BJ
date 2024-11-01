#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10 , N1 = 1e6 + 10;

struct node
{
    int s , e , c = 0;
    long long v;
    bool flag = false;
}cnt[N1] , g[N1];

int a[N] , f[N];
bool flag[N];

bool cmp (node x , node y)
{
    return x.s < y.s;
}

int main()
{
    freopen("color.in" , "r" , stdin);
    freopen("color.out" , "w" , stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(flag , false , sizeof flag);
        memset (cnt , 0 , sizeof cnt);
        memset (g , 0 , sizeof g);

        int n;
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i];
            if(!cnt[a[i]].flag) cnt[a[i]].s = i , cnt[a[i]].e = i , cnt[a[i]].flag = true , cnt[a[i]].c++;
            else cnt[a[i]].e = i , cnt[a[i]].c++;
        }

        int cur = 0;
        for (int i = 1;i <= n;i++)
        {
            cnt[a[i]].v = a[i] * (cnt[a[i]].c - 1);
            if (cnt[a[i]].c >= 2) g[++cur] = cnt[a[i]];
        }
        sort(g + 1 , g + cur + 1 , cmp);

        long long ans = 0;
        for (int i = 1;i <= cur;i++)
        {
            if (g[i].s < g[i - 1].e && flag[i] == false) continue;
            if (g[i].e > g[i + 1].s)
                if (g[i].v > g[i - 1].v) flag[i] = true , ans = ans + g[i].v;
            if (g[i].s > g[i - 1].e && g[i].e < g[i + 1].s) ans = ans + g[i].v;
            if (g[i].s < g[i - 1].e && g[i].e > g[i + 1].s) ans = ans + max({g[i].v , g[i - 1].v , g[i + 1].v});       
        }
        cout << ans << endl;
    }
    return 0;
}