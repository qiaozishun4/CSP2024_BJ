#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int T, n, w;
int sk[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int number[] = {0, 2, 1, 3, 2, 1, 1};
bool flag = 0;

int check(int x) {
    int ans = 0;
    while(x > 0) {
        ans += sk[x%10];
        x/=10;
    }
    return ans;
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--) {
        flag = 0;
        cin >> n;
        if(n < 2) {
            cout << -1 << endl;
            continue;
        }
        else if(n < 22) {
            for(int i = 1; i <= N; i++) {
                if(check(i) == n) {
                    cout << i << endl;
                    flag = 1;
                    break;
                }
            }
            if(!flag) cout << -1 << endl;
        }
        else {
            w = n / 7;
            if(n % 7 != 0) w++;
            if(n % 7 == 1) {
                cout << 10;
            }
            else if(n%7 == 2) {
                cout << 1;
            }
            else if(n%7 == 3) {
                cout << 200;
            }
            else if(n%7 == 4) {
                cout << 20;
            }
            else if(n%7 == 5) {
                cout << 2;
            }
            else if(n% 7 == 6) {
                cout << 6;
            }
            for(int i = 1; i <= w - number[n%7]; i++) cout << 8;
            cout << endl;
        }
    }
    return 0;
}