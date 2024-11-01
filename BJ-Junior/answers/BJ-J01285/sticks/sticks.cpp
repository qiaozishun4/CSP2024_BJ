#include <bits/stdc++.h>
using namespace std;

int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string nf(int n, int minl){
    if(minl == 0){
        return "";
    }
    if(n % 7 == 0){
        string ans = "";
        for(int i = 1; i <= n / 7; i++){
            ans = ans + '8';
        }
        return ans;
    }
    for(int i = 0; i < 10; i++){
        if(n >= a[i] && (n - a[i] + 6) / 7 == minl - 1 && n - a[i] != 1){
            string ans = char('0' + i) + nf(n - a[i], minl - 1);
            return ans;
        }
    }
}
string isf(int n, int minl){
    if(n % 7 == 0){
        string ans = "";
        for(int i = 1; i <= n / 7; i++){
            ans = ans + '8';
        }
        return ans;
    }
    for(int i = 1; i < 10; i++){
        if(n >= a[i] && (n - a[i] + 6) / 7 == minl - 1 && n - a[i] != 1){
            string ans = char('0' + i) + nf(n - a[i], minl - 1);
            return ans;
        }
    }
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << "-1\n";
            continue;
        }
        cout << isf(n, (n + 6) / 7) << '\n';
    }
    return 0;
}
