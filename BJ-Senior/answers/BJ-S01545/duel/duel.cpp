#include<bits/stdc++.h>
using namespace std;
int n, a[100005], ans = 0;
stack<int> st, str;
int du() {
    int cnt = 0;
    st.push(a[0]);
    for(int i = 1; i < n; i++) {
        if(a[i] == st.top()) {
            str.push(a[i]);
        }else{
            st.push(a[i]);
            cnt++;
        }
    }
    if(cnt) {
        return 1;
    }
    return 0;
}
int main() {
    freopen("duel.in", "r",stdin);
    freopen("duel.out", "w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = 0;
    sort(a, a + n);
    ans += du();
    int s = 0;
    while(!str.empty() && s < 100002) {
        for(int i = 0; i < n; i++) {
            if(!st.empty()) {
                st.pop();
            }
            if(!str.empty()) {
                a[i] = str.top();
                str.pop();
            }else{
                a[i] = 0x3f3f;
            }
        }
        s++;
        sort(a, a + n);
        ans += du();
    }
    if(ans > 1 && ans == n - 1) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}