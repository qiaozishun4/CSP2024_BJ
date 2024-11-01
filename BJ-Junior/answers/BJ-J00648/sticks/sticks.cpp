#include<bits/stdc++.h>
using namespace std;
const int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
inline int get(int x, bool flag){
    if(flag){
        if(x <= 2) return 1;
        if(x == 3) return 2;
        if(x == 4) return 2;
        if(x == 5) return 2;
        if(x == 6) return 6;
        if(x == 7) return 8;
    }else{
        if(x <= 6) return 0;
        else return 8;
    }
    return -1;
}
inline int musteze(int x){
    if(x == 2) return 1;
    if(x == 3) return 7;
    if(x == 4) return 4;
    if(x == 5) return 2;
    if(x == 6) return 0;
    if(x == 7) return 8;
    return -1;
}
inline void Solve(int n){
    if(n == 1){
        cout << -1 << endl;
        return;
    }
    int ws = n / 7;
    if(n % 7 != 0) ws++;
    if(ws == 1){
        if(n == 6){
            cout << 6 << endl;
            return;
        }
        cout << musteze(n) << endl;
        return;
    }
    int firsttt_min = n - (ws-1) * 7;
    int bgg = get(firsttt_min, true);
    cout << bgg;
    n -= num[bgg];
    for(int i = 2; i < ws; i++){
        int noww = n - (ws-i) * 7;
        bgg = get(noww, false);
        cout << bgg;
        n -= num[bgg];
    }
    cout << musteze(n) << endl;
    return;
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        Solve(n);
    }
    return 0;
}