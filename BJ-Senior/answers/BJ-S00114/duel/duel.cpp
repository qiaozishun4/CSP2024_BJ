#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;
const int N = 100005;
int n;
stack <int> st2;
queue <int> q1;
int a[N];
int Cal() {
    int ret = 0;
    while ( !st2.empty()) {
        if ( q1.empty()) {
            q1.push(st2.top());
            st2.pop();
        }
        while ( !st2.empty() && st2.top() <= q1.front()) {
            q1.push(st2.top());
            st2.pop();
        }
        if ( !q1.empty() && !st2.empty()) {
            q1.pop();
            q1.push(st2.top());
            st2.pop();
        }
    }
    while ( !q1.empty()) {
        ret++;
        q1.pop();
    }
    return ret;
}
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    int ans = 0;
    for ( int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for ( int i = n; i >= 1; i--) {
        st2.push(a[i]);
    }
    ans = Cal();
    cout << ans << endl;
    return 0;
}