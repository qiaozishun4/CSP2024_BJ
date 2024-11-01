#include <bits/stdc++.h>
using namespace std;
int n, a[100001], rest;
int cnt[100001];
set<int> st;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i], cnt[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) st.insert(a[i]);
    int x = 0;
    for(int i : st) {
        x++;
        if(x == 1) {
            rest = cnt[i];
            continue;
        }
        if(cnt[i] >= rest) rest = cnt[i];
    }
    cout << rest << endl;
    return 0;
}