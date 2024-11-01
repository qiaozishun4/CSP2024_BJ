#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 1e5 + 5;
int n; map<string, int> m;
signed main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) {
        string s; cin>>s;
        m[s]++;
    } 
    cout<<52 - m.size()<<endl;
    return 0;
}

/* 游记
07:15 起床，打了一遍 Dij 板子，洗漱吃饭。
08:08 到达北工大，好多小朋友吊打我 /ll
08:30 开始考试。
08:39 T1 什么弱智题，直接开个 map，答案就是 $52-\text{size}()$。切掉。
09:03 T2 什么傻卵题，直接模拟即可，复杂度是 $\mathcal{O}(k)$ 的。切掉。
09:29 读完了 T3 T4，会 T4 不会 T3？T3 不给大样例？
09:59 好像会 T3 了，分类讨论 $n\bmod7$，考虑构造 $\tt xx888$ 的形式。会赢吗？
10:44 T3 什么规律题，打个表就做完了，跟我的 $\mathcal{O}(10^{n/7})$ 暴力拍了下，应该没问题。切掉。
11:20 发现 T4 是假的 /ll
11:58 交完了，T4 写个不知道多少分的暴力，遗憾离场。
*/