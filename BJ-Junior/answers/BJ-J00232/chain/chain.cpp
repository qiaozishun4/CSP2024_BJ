#include <iostream>
using namespace std;
#define ll long long
ll T, n, k, q, r, c;
string str[100010];
bool check(ll le, ll ri) {
    bool flag1 = false, flag2 = false;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < str[i].size(); j++) {
            if(str[i][j] == '1') {
                flag1 = true;
            }
            if(str[i][j] == (char){ri + '0'}) {
                flag2 = true;
            }
        }
    }
    if(flag1 == true && flag2 == true) {
        return true;
    }
    return false;
}
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++) {
            ll cc = 0;
            char ch;
            while(cin >> ch) {
                if(ch == ' ') {
                    continue;
                }
                str[i][cc] = ch;
                cc++;
            }
        }
        for(int i = 1; i <= q; i++) {
            cin >> r >> c;
            if(n < 2) {
                cout << 0;
            }
            if(n == 2) {
                bool fla = 0, flag = 0;
                for(int j = 1; j <= str[1].size(); j++) {
                    if(str[2][j] == c) {
                        fla = 1;
                    }
                    if(str[2][j] == '1') {
                        flag = 1;
                    }
                }
                for(int j = 1; j <= str[2].size(); j++) {
                    if(str[2][j] == c) {
                        fla = 1;
                    }
                    if(str[2][j] == '1') {
                        flag = 1;
                    }
                }
                if(fla && flag) {
                    cout << 1 << endl;
                }
                else {
                    cout << 0 << endl;
                }
            }
            if(!check(1, c)) {
                cout << 0 << endl;
                continue;
            }
            cout << 1;
        }
    }


    return 0;
}
