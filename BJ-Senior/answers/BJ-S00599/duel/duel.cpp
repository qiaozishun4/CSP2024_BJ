#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define F(n) for(int i = 1; i <= n; i++)
#define Fi(i, n) for(int i = 1; i <= n; i++)
int n, r[100005], cnt[100005];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    F(n){
        cin >> r[i];
        cnt[r[i]]++;
    }
    int ans = 0;
    F(100000){
        ans = max(ans, cnt[i]);
    }
    cout << ans;
    return 0;
}
