#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, M = 1e6 + 5;
int T, n, a[N], d[M], dp[N], pre[N], lst[M], sum[N], nd[M];
vector<int>color[M];
unordered_set<int>can_ch;
signed main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        memset(d, 0, sizeof d);
        memset(nd, 0, sizeof nd);
        memset(lst, 0, sizeof lst);
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            if(!lst[a[i]])color[a[i]].clear();
            pre[i] = lst[a[i]];
            lst[a[i]] = i;
            color[a[i]].push_back(i);
        }
        can_ch.clear();
        for(int i = 1;i <= n;i++){
            int x = a[i];
            sum[i] = sum[i - 1];
            if(can_ch.count(x))sum[i] += x;
            else can_ch.insert(x);
        }
        for(int i = 2;i <= n;i++){
            int x = a[i], pr = pre[i];
            dp[i] = dp[i - 1];
            if(pr == 0)continue;
            int nv = d[x] + sum[i];
            dp[i] = max(dp[i], nv);
            d[x] = max(d[x], dp[i]);
//            cout << "dp[" << i << "]=" << dp[i] << '\n';
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
