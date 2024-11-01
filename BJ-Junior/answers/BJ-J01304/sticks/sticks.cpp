#include <bits/stdc++.h>
using namespace std;
int a[10] = {1, 5, 2, 2, 3, 2, 1, 4, 0, 1}, b[100005];
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    int len = 0;
    for(int i = 1; i <= 100000; i++){
        if(i % 7 == 0) b[++len] = i;
    }
    while(T--){
        int n; cin >> n;
        int ans = -1;
        if(n <= 7){
            for(int i = 1; i <= 9; i++){
                if(7 - a[i] == n){
                    ans = i;
                    break;
                }
            }
            cout << ans << endl;
        }
        else if(n <= 14){
            int id = lower_bound(b + 1, b + len + 1, n) - b;
            int sum = b[id] - n;
            if(sum == 0) cout << 88;
            if(sum == 1) cout << 68;
            if(sum == 2) cout << 28;
            if(sum == 3) cout << 20;
            if(sum == 4) cout << 22;
            if(sum == 5) cout << 18;
            if(sum == 6) cout << 10;
            for(int i = 3; i <= id; i++) cout << 8;
            cout << endl;
        }
        else{
            int id = lower_bound(b + 1, b + len + 1, n) - b;
            int sum = b[id] - n;
            if(sum == 0) cout << 888;
            if(sum == 1) cout << 688;
            if(sum == 2) cout << 288;
            if(sum == 3) cout << 208;
            if(sum == 4) cout << 200;
            if(sum == 5) cout << 188;
            if(sum == 6) cout << 108;
            for(int i = 4; i <= id; i++) cout << 8;
            cout << endl;
        }
    }
    return 0;
}
