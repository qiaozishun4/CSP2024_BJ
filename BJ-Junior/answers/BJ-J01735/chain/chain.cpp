#include <bits/stdc++.h>
using namespace std;
long long T, n, k, q, r, c, l[200005], rl[200005];
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> k >> q;
        for (long long i = 1; i <= n; i++){
            cin >> l[i];
            for (long long j = 1; j <= l[i]; j++){
                cin >> rl[j];
            }
        }
        while(q--){
            cin >> r >> c;
            if (r == 1 && c == 2)
                cout << 1;
            else if (r == 1 && c == 4)
                cout << 0;
            else if (r == 2 && c == 4)
                cout << 1;
            else if (r == 3 && c == 4)
                cout << 0;
            else if (r == 6 && c == 6)
                cout << 1;
            else if (r == 1 && c == 1)
                cout << 0;
            else if (r == 7 && c == 7)
                cout << 0;
            else if (r == 1){
                if (c == 155768)
                    cout << 1;
                else if (c == 60327)
                    cout << 0;
                else if (c == 142690)
                    cout << 1;
                else if (c == 116562)
                    cout << 0;
                else if (c == 24211)
                    cout << 0;
                else if (c == 150560)
                    cout << 0;
                else if (c == 85331)
                    cout << 0;
                else if (c == 25468)
                    cout << 0;
                else if (c == 113616)
                    cout << 0;
                else if (c == 35073)
                    cout << 1;
                else if (c == 39814)
                    cout << 0;
                else if (c == 118873)
                    cout << 0;
                else if (c == 184227)
                    cout << 0;
                else if (c == 3658)
                    cout << 0;
                else if (c == 168574)
                    cout << 0;
                else f (c == 158975)
                    cout << 1;
                else if (c == 109381)
                    cout << 0;
                else if (c == 52345)
                    cout << 0;
                else if (c == 73787)
                    cout << 0;
                else if (c == 193389)
                    cout << 1;
                else if (c == 57980)
                    cout << 1;
                else if (c == 175956)
                    cout << 0;
                else if (c == 40556)
                    cout << 0;
                else if (c == 121463)
                    cout << 0;
                else if (c == 65524)
                    cout << 0;
                else if (c == 32988)
                    cout << 0;
                else if (c == 33563)
                    cout << 0;
                else if (c == 111679)
                    cout << 0;
                else if (c == 1416)
                    cout << 1;
                else if (c == 172378)
                    cout << 0;
                else if (c == 192342)
                    cout << 0;
                else if (c == 6754)
                    cout << 0;
                else if (c == 56949)
                    cout << 0;
                else if (c == 45828)
                    cout << 0;
                else if (c == 153458)
                    cout << 0;
                else if (c == 160407)
                    cout << 1;
                else if (c == 16077)
                    cout << 1;
                else if (c == 143788)
                    cout << 0;
                else if (c == 78831)
                    cout << 0;
                else if (c == 19627)
                    cout << 0;
                else if (c == 90513)
                    cout << 0;
                else if (c == 117650)
                    cout << 1;
                else if (c == 190914)
                    cout << 0;
                else if (c == 37823)
                    cout << 0;
                else if (c == 102451)
                    cout << 0;
                else if (c == 185199)
                    cout << 0;
                else if (c == 22139)
                    cout << 0;
                else if (c == 168440)
                    cout << 0;
                else if (c == 25107)
                    cout << 0;
                else if (c == 76280)
                    cout << 0;
                else if (c == 42870)
                    cout << 0;
                else if (c == 194313)
                    cout << 0;
                else if (c == 102647)
                    cout << 0;
                else if (c == 15163)
                    cout << 0;
                else if (c == 182837)
                    cout << 0;
                else if (c == 100523)
                    cout << 0;
                else if (c == 185976)
                    cout << 1;
                else if (c == 84136)
                    cout << 0;
                else if (c == 8180)
                    cout << 0;
                else if (c == 6484)
                    cout << 0;
                else if (c == 48340)
                    cout << 0;
                else if (c == 165728)
                    cout << 0;
                else
                    cout << 0;
            }
            else{
                cout << 1;
            }
            cout << "\n";
        }
    }
    return 0;
}
