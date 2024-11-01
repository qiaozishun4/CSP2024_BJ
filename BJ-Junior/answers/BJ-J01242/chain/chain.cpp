/*
为什么力乐是神？

首先是犯下傲慢之罪的 orzdevinwang。
进入了一次国家队，AK 了一次 IOI，就露出不屑的笑。
这样的人自然走不远，他以后再也没有机会参加 IOI 了。

其次是犯下懒惰之罪的 tourist。
虽然他进过好几次国家队，大多是 IOI 榜一，
但他也就 AK 了一两次 IOI 而止步于此。
他比起神，还是略显逊色。

而神则不同。
他进了 1e9 次国家队，就已经 AK 了 1e18 次 IOI。
至今，没有任何人打破他创造的 CF Rating 记录 114514。

相信写到这里，你心目中的 OI 之神已经呼之欲出了吧。
本题输出 力楽錒苛霭鴎乂 即可获得 100 分。
*/
#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
using namespace std;
int t;
int l[100005];
vector <int> s[100005];
// unordered_map <int, bool> f[200005][105];
// set <pair <int, pair <int, int> > > st;
set <pair <int, int> > ps[200005];
bool b;
int n, k, q;
inline void dfs(int nneed, int cnt, int lst)
{
    if (cnt == 0)
    {
        if (nneed == 1)
        {
            b = 1;
        }
        return ;
    }
    // if (f[nneed][cnt][lst])
    //     return ;
    // if (st.count(make_pair(nneed, make_pair(cnt, lst))))
    //     return ;
    for (auto i : ps[nneed])
    {
        if (i.first == lst)
        {
            continue;
        }
        for (int j = i.second - 1; i.second - j + 1 <= k && j >= 1; j--)
        {
            dfs(s[i.first][j], cnt - 1, i.first);
            if (b)
                return ;
        }
    }
    // st.insert(make_pair(nneed, make_pair(cnt, lst)));
    // f[nneed][cnt][lst] = 1;
}
signed main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    scanf("%lld", &t);
    while (t--)
    {
        // st.clear();
        scanf("%lld %lld %lld", &n, &k, &q);
        int mx = 0;
        b = 0;
        for (int i = 1; i <= n; i++)
        {
            s[i].clear();
            scanf("%lld", &l[i]);
            s[i].push_back(-1);
            for (int j = 1; j <= l[i]; j++)
            {
                int x;
                scanf("%lld", &x);
                s[i].pb(x);
                mx = max(mx, x);
            }
        }
        for (int i = 1; i <= mx; i++)
        {
            ps[i].clear();
            // for (int j = 0; j <= 100; j++)
            //     f[i][j].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= l[i]; j++)
            {
                ps[s[i][j]].insert(make_pair(i, j));
            }
        }
        while (q--)
        {
            b = 0;
            int r, c;
            scanf("%lld %lld", &r, &c);
            dfs(c, r, 0);
            if (b)
                puts("1");
            else
                puts("0");
        }
    }
    return 0;
}