#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N], n;

multiset<int> st;

bool check(int k){
    for(int i = n - k + 1; i <= n; i++) st.insert(a[i]);
    for(int i = n - k; i >= 1; i--){
        auto p = st.upper_bound(a[i]);
        if(p == st.end()) return false;
        st.erase(st.find(*p)); st.insert(a[i]);
    }

    return true;
}

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
