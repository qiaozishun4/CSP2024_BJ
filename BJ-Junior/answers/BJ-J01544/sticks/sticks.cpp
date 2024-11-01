#include<bits/stdc++.h>
using namespace std;
int a[10] = {6, 2, 5, 4, 6, 3, 7};
int b[10] = {0, 1, 2, 4, 6, 7, 8};

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        int n;
        cin >> n;
        if (n == 1){
            cout << -1 << '\n';
            continue;
        }
        int ws = (n - 1) / 7 + 1;
        if ((n % 7) == 0){
            for (int j = 1; j <= ws; j++)
                cout << 8;
            cout << '\n';
            continue;
        }
        if (n == 2){
            cout << 1 << '\n';
            continue;
        }
        if (n == 3){
            cout << 7 << '\n';
            continue;
        }
        if (n == 4){
            cout << 4 << '\n';
            continue;
        }
        if (n == 5){
            cout << 2 << '\n';
            continue;
        }
        if (n == 6){
            cout << 6 << '\n';
            continue;
        }
        if ((n % 7 == 6)){
            cout << 6;
            for (int j = 1; j < ws; j++)
                cout << 8;
            cout << '\n';
            continue;
        }
        int tmp = 6 * ws;
        if (tmp == n){
            cout << 2;
            for (int j = 1; j <= (ws - 2); j++)
                cout << 0;
            cout << 8 << '\n';
            continue;
        }
        if (tmp < n){
            int tmp1 = n - tmp;
            if (ws > (tmp1 + 5)){
                cout << 1;
                for (int j = 2; j <= (n - 4); j++)
                    cout << 0;
                cout << 8888 << '\n';
                continue;
            }
        }
        if (tmp > n){
            int tmp1 = tmp - n;
            int tmp2 = tmp1 / 4;
            cout << 1;
            for (int j = 2; j <= (n - tmp2 - 1); j++)
                cout << 0;
            int tmp3 = tmp1 % 4;
            if (tmp3 == 0)
                cout << 0;
            for (int j = 1; j <= tmp2; j++)
                cout << 1;
            if (tmp3 == 1)
                cout << 2;
            if (tmp3 == 2)
                cout << 4;
            if (tmp3 == 3)
                cout << 7;
            cout << '\n';
        }
    }

    return 0;
}