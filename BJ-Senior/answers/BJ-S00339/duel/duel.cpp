#include <bits/stdc++.h>
using namespace std;
int n, r[100005], ans = 0;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    for(int i = 1;i <= n;i++){
        if(r[i] > r[ans + 1]){
            ans++;
        }
    }
    cout << n - ans << "\n";
    return 0;
}
