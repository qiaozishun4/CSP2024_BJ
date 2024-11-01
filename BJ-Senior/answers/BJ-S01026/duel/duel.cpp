#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
map <int, int> mp;
signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        mp[a[i]]++;
    }
    // for (auto p : mp)
    // {
    //     printf("%lld:%lld\n", p.first, p.second);
    // }
    auto it1 = mp.begin();
    it1++;
    auto it = mp.begin();
    while (it1 != mp.end())
    {
        int delta = 0;
        // printf("%lld:%lld %lld:%lld\n", it->first, it->second, it1->first, it1 ->second);
        delta = min(it1 -> second, it -> second);
        (it -> second) -= delta;
        // printf("after: %lld:%lld %lld:%lld\n", it->first, it->second, it1->first, it1 ->second);
        // puts("");
        while (it->second > 0 && it1 != mp.end())
        {
            it1++;
            // printf("%lld:%lld %lld:%lld\n", it->first, it->second, it1->first, it1->second);
            delta = min(it1 -> second, it -> second);
            it -> second -= delta;
            // printf("after:%lld:%lld %lld:%lld\n", it->first, it->second, it1->first, it1 ->second);
            // puts("");
        }
        do
        {
            it++;
        } while (it -> second == 0);
        if (it1 == it)
            it1++;
    }
    int cnt = 0;
    // puts("");
    for (auto i : mp)
    {
        // printf("%lld:%lld\n", i.first, i.second);
        cnt += i.second;
    }
    printf("%lld", cnt);
    return 0;
}