#include <bits/stdc++.h>
using namespace std;
int a[100011];
int t[100011];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, maxn = INT_MIN;
    cin >> n;
    int ans = n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        maxn = (maxn, a[i]);
        t[a[i]]++;
    }
    for (int i = 0; i <= maxn; i++){
        int ji = 0;
        if (t[i] > 0){
            for (int j = maxn; j >= 1; j--){
                if (j < i && t[j] > 0 && ji <= t[i]){
                    t[j] = t[j] - 1;
                    ans = ans - 1;
                    ji = ji + 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
