#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
long long tenpow(int hq){
    if (hq == 0)  return 1;
    if (hq == 1){
        return 10;
    }
    return 10 * tenpow(hq-1);
}
int stick(long long a){
        if (n <= 1) return -1;
        if (n == 3) return 7;
        if (n == 4) return 4;
        if (n == 5) return 5;
        if (n == 6) return 6;
        if (n == 10) return 22;
        if (n == 11) return 26;
        if (n % 7 == 0){
            int factor_with_no_name=0;
            for (int i=0;i<n/7;i++){
                factor_with_no_name += 8 * tenpow(i);
            }
            return factor_with_no_name;
        }
        if (n % 7 == 1){
            int factor_without_name=0;
            for (int i=0;i<n/7;i++){
                factor_without_name += 8 * tenpow(i);
            }
            factor_without_name += 2 * tenpow(n/7-1);
            return factor_without_name;
        }
        if (n % 7 == 2){
            int factor_with_name=0;
            for (int i=0;i<n/7;i++){
                factor_with_name += 8 * tenpow(i);
            }
            factor_with_name += 1 * tenpow(n/7);
            return factor_with_name;
        }
        if (n % 7 == 5){
            int factor=0;
            for (int i=0;i<n/7;i++){
                factor += 8 * tenpow(i);
            }
            factor += 2 * tenpow(n/7);
            return factor;
        }
        if (n % 7 == 6){
            int a_factor=0;
            for (int i=0;i<n/7;i++){
                a_factor += 8 * tenpow(i);
            }
            a_factor += 6 * tenpow(n/7);
            return a_factor;
        }
        if (n % 7 == 3){
            int afactor=0;
            for (int i=0;i<n/7;i++){
                afactor += 8 * tenpow(i);
            }
            afactor += 7 * tenpow(n/7);
            return afactor;
        }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        cout << stick(n) << endl;
    }
    return 0;
}
