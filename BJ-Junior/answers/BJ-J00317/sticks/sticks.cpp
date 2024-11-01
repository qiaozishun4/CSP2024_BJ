#include<bits/stdc++.h>
using namespace std;
int T, n;
int mp[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int calc(int x) {
    if(x==0) return 6;
    int ret = 0;
    while(x) {
        ret+=mp[x%10];
        x/=10;
    }
    return ret;
}
int calc2(int n){
    for(int i = 0; i <= 100000; i++) {
        if(calc(i)==n) {
            return i;
        }
    }
    return 0;
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        if(n==1) {
            cout << -1 << '\n';
            continue;
        }
        if(n==6) {
            cout << 6 << '\n';
            continue;
        }
        if(n%7==0) {
            cout << 8;
        }
        int cnt = (n-7)/7;
        int othe = n-cnt*7;
        if(n%7!=0) cout << calc2(othe);
        for(int i = 1; i <= cnt; i++) cout << 8;
        cout <<'\n';
    }
    return 0;
}
