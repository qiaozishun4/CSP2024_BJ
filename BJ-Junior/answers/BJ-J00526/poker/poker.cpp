#include <bits/stdc++.h>
using namespace std;

int a[60];
int sum = 1;

int main(){

    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n, ans = 52;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        int p = 0;

        char h, s;
        cin >> h, s;

        if (h == 'D') p += 100;
        if (h == 'C') p += 200;
        if (h == 'H') p += 300;
        if (h == 'S') p += 400;
        if (s == 'A') p += 1;
        if (s == '2') p += 2;
        if (s == '3') p += 3;
        if (s == '4') p += 4;
        if (s == '5') p += 5;
        if (s == '6') p += 6;
        if (s == '7') p += 7;
        if (s == '8') p += 8;
        if (s == '9') p += 9;
        if (s == 'T') p += 10;
        if (s == 'J') p += 11;
        if (s == 'Q') p += 12;
        if (s == 'K') p += 13;

        bool res = true;

        for (int i = 1; i <= sum; i ++){
            if (p == a[i]){
                res = false;
                break;
            }
        }
        if (res){
            a[sum] = p;
            ans --;
            sum ++;
        }
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
