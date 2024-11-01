#include <bits/stdc++.h>

using namespace std;
int n, cnt2, x, cnt1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> x;
        if(x == 1){
            ++cnt1;
        }
        if(x == 2){
            ++cnt2;
        }
    }
    if(cnt2 >= cnt1){
        cout << cnt2;
    } else {
        cout << cnt1;
    }
    return 0;
}
