#include <bits/stdc++.h>
using namespace std;

// 0: 6
// 1: 2
// 7: 3
// 4: 4
// 2: 5
// 6: 6
// 8: 7

string solve(int n) {
    if (n <= 1) return "-1";
    if (n == 2) return "1";
    if (n == 3) return "7";
    if (n == 4) return "4";
    if (n == 5) return "2";
    if (n == 6) return "6";
    if (n == 7) return "8";
    // 不存在n>=8且返回-1

    string r;
    if (n % 7 == 0) { r="8"; }  //7
    if (n % 7 == 1) { r="10"; } //8
    if (n % 7 == 2) { r="18"; } //9
    if (n % 7 == 3) { r="22"; } //10
    if (n % 7 == 4) { r="20"; } //11
    if (n % 7 == 5) { r="28"; } //12
    if (n % 7 == 6) { r="68"; } //13

    for (int i=0;i<n/7-1;i++) r += "8";
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        string r = solve(n);
        cout<<r<<endl;
    }

    return 0;
}
