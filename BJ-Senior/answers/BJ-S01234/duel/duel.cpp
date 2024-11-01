#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 1e5 + 5;
int n, a[N], p[N], ans = 1;
// map<int, int> m; vector<string> sol;
signed main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i]; // m[a[i]]++;
    // for(auto [x, y] : m) cout<<x<<" "<<y<<endl;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) if(a[ans] < a[i]) ans++; 
        // sol.push_back(to_string(a[i]) + " vs " + to_string(a[ans - 1]));
    cout<<n - (ans - 1)<<endl;
    // string p; int cnt = 0;
    // for(string i : sol)  
    //     if(i == p) cnt++;
    //     else cout<<p<<" "<<cnt<<endl, p = i, cnt = 1;
    return 0;
}

/* 游记
12:00 考试结束。
12:30 跟亦中的同学吃了个饭，在餐厅打完了 SegTree & Kruskal & Tarjan & LCA 等板子。
13:45 前往考场。
14:10 在考场门口用手机复习了下串串，包括 Kmp 和 Hash 啥的。
14:30 考试开始。
14:41 写完了 Judger，开 T1。
14:55 这么典的题？贪心即可。但我写的 $i$ 从大往小枚举。
15:03 样例 #4 没过？思考许久，考虑用 set 维护。
15:43 突发奇想，把一开始的代码改成从小往大枚举，过了？我是唐诗。切掉。
15:50 开 T2。
17:03 T2 经过一系列转化，变为给定 $n$ 条线段，问最少需要多少个点使得每条线段至少覆盖了 $1$ 个点。我不会了啊！只会 $\mathcal{O}(n^2)$ 的暴力，拼个包就能有 90？爽！
17:23 会正解了！排序之后贪心即可。测了下大样例，除了 #3-9 都过了！注意到第一个答案是 $0$，不妨加个特判。赢啦！最大的点 1.13s！切掉.
17:29 开 T3 T4。
18:27 T3 T4 都不会啊，打个暴力走人 /ll
18:30 考试结束。

预估 J 组 300+，S 组 200+。
*/
