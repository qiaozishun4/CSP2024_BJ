#include<bits/stdc++.h>

using namespace std;
string p[4] = {"D", "C", "H", "S"};
string q[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            bool is = true;
            for(int k = 0; k < n; k++) {
                if(a[k] == p[i] + q[j]) {
                    is = false;
                    break;
                }
            }
            if(is) ans++;
        }
    }

    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
