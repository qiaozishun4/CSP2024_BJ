#include<bits/stdc++.h>

using namespace std;

int n, k, t;//weishu
int len = 90000000;
int p, q;

int m[] = {-1, -1, 1, 7, 4, 2, 6, 8, -1, -1};
int mp[] = {10, 24, 22, 27, 28, 68};
int dx[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> n;

    while (n --){
        scanf("%d", &k);
        if (k == 1){
            cout << -1 << '\n';
            continue;
        }
        else if (1 < k && k <= 7){
            if (k == 6) cout << 6;
            else cout << m[k];

            puts("");
        }
        else if (k % 7 == 0){
            while (k > 1) {cout << 8; k -= 7;}
            puts("");
        }
        else if (k > 7 && k < 56){
            int cnt, j;
            for(int i = 10; i < len; i++){
                cnt = 0, j = i;
                while (j > 0) {
                    cnt += dx[j % 10];
                    j /= 10;
                }
                if (cnt == k){
                    cout << i << '\n';
                    break;
                }
            }
        }
        else if (k % 7 == 1) {
            cout << 10 ;
            int cmp = k / 7 - 1;
            while (cmp --){cout << 8;}
            puts("");
        }
        else {
            t = k / 7 - 1;
            q = p = k % 7 - 1;
            cout << mp[q];
            while (t --) {cout << 8;}
            puts("");
        }
    }

    return 0;
}
