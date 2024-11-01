#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, K = 20;
int n, m, a[N], A[N], c[N], T, ans, k;
bool d[K][N];
int pw[K], nd[N];
bool tag[N * 2];
int solve(int n, vector<int>v, int p){
    if(v.size() == 1){
        int res = 0;
        for(auto i : v){
            res += i + 1;
        }
        return res;
    }
    vector<int>nv;
    for(int i = 0;i < n / 2;i++){
        bool typ = d[p][i];
        int x = v[i * 2], y = v[i * 2 + 1];
        if(typ){
            if(a[y + 1] >= p)nv.push_back(y);
            else{
                nv.push_back(x);
            }
        }else{
            if(a[x + 1] >= p)nv.push_back(x);
            else nv.push_back(y);
        }
    }
    return solve(n / 2, nv, p + 1);
}
signed main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pw[0] = 1;
    for(int i = 1;i < K;i++){
        pw[i] = pw[i - 1] * 2;
    }
    for(int i = 1;i <= n;i++){
        cin >> A[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> c[i];
        nd[i] = lower_bound(pw, pw + K, c[i]) - pw;
    }
    k = lower_bound(pw, pw + K, n) - pw;
//    cout << k <<'\n';
    for(int i = k - 1;i >= 0;i--){
        for(int j = 0;j < pw[i];j++){
            char c;
            cin >> c;
            d[k - i][j] = c - '0';
        }
    }
    cin >> T;
    while(T--){
        int x[4];
        for(int i = 0;i < 4;i++)cin >> x[i];
        for(int i = 1;i <= n;i++){
            a[i] = A[i] ^ x[i % 4];
        }
        ans = 0;
        for(int i = 1;i <= m;i++){
            vector<int>tmp;
            for(int j = 0;j < c[i];j++)tmp.push_back(j);
            ans = ans ^ (solve(c[i], tmp, 1) * i);
        }
        cout << ans << '\n';
    }
    return 0;
}
