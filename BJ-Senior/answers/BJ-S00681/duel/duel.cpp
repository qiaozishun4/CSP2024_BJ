

#include <bits/stdc++.h>

using namespace std;

const int mx = 100010;
int n, a[mx], cnt;
bool vis[mx];

inline int sch(int x){
    int l = 1, r = x - 1, ans = x - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(!vis[mid]) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 2; i <= n; i++){
        int t = sch(i);
       // cerr << i << ' ' << t << endl;
        if(a[i] != a[t]) cnt++, vis[t] = true;
    }
    cout << n - cnt << '\n';
    return 0;
}