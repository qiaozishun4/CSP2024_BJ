#include <bits/stdc++.h>
using namespace std;
string sn(int l, int isr=0){
    if(l < 2){
        return "-1";
    }
    if(l < 8){
        int t[8] = {-1, -1, 1, 7, 4, 2, 6, 8};
        if(isr == 1){
            t[6] = 0;
        }
        return to_string(t[l]);
    }
    // Magic
    string sf[7] = {"", "10", "1", "22", "20", "2", "6"};
    int ld7 = l / 7, lm7 = l % 7;
    if(sf[lm7].size() == 2){
        ld7--;
    }
    string s = sf[lm7];
    for(int i = 1;i <= ld7;i++){
        s += '8';
    }
    return s;
}
int main(){
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << sn(n) << endl;
    }
    return 0;
}
