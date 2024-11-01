#include <bits/stdc++.h>
using namespace std;
int T;
int quan[] = {6,   2,   5,   4,   6,   3,   7};
char zi[] = {'0', '1', '2', '4', '6', '7', '8'};
vector<int> ans;
string minn;
int x;
void dfs(string now, int use) {
    if(use == x) {
        if(minn.size() == 0) {
            minn = now;
        }else{
            if(minn.size() > now.size()) {
                minn = now;
            }else{
                minn = min(minn, now);
            }
        }

        return;
    }
    if(minn.size() < now.size()) {
        return;
    }
    if(use > x) {
        return;
    }
    for(int i = 0; i < 7; i++) {
        if(now.size() == 0 && i == 0) {
            continue;
        }
        string indx = now;
        indx.push_back(zi[i]);
        dfs(indx, use + quan[i]);
    }
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> x;
        if(x == 1 || x == 0) {
            cout << -1 <<"\n";
            continue;
        }
        if(x >= 15) {
            x -= 15;
            if(x % 7 == 0 || x % 7 == 1) {
                cout << 1;
                for(int i = 0; i < 1 - x % 7; i++) {
                    cout << 0;
                }
                for(int i = 0; i < (3 + x / 7) - (1 - x % 7) - 1; i++) {
                    cout << 8;
                }
            }
            if(x % 7 == 2 || x % 7 == 3 || x % 7 == 4) {
                cout << 2;
                for(int i = 0; i < 4 - x % 7; i++) {
                    cout << 0;
                }
                for(int i = 0; i < (3 + x / 7) - (4 - x % 7) - 1; i++) {
                    cout << 8;
                }
            }
            if(x % 7 == 5) {
                cout << 6;
                for(int i = 0; i < (3 + x / 7)  - 1; i++) {
                    cout << 8;
                }
            }
            if(x % 7 == 6) {
                cout << 8;
                for(int i = 0; i < (3 + x / 7) - 1; i++) {
                    cout << 8;
                }
            }
            cout << "\n";
        }else {
            for(int i = 0; i < 10005; i++) {
                minn.push_back('a');
            }
            dfs("", 0);

            cout << minn <<"\n";
        }
    }
    return 0;
}
/*
6
1
2
3
6
18
28
*/
