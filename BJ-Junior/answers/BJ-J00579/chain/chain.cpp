#include <bits/stdc++.h>
using namespace std;
int T;
int l[1005];
vector<int> v[1005];

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while(T--) {
        int n, k, q;
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++) {
            cin >> l[i];
            for(int j = 1;j <= l[i];j++) {
                int x;
                cin >> x;
                v[i].push_back(x);
            }
        }
        while(q--) {
            int r, c;
            cin >> r >> c;
            if(r == 1) {
                bool fl = 0;
                for(int i = 1;i <= n;i++) {
                    for(int j = 0;j < l[i];j++) {
                        if(v[i][j] == 1) {
                            for(int l = 1;l < k;l++) {
                                if(v[i][j + l] == c)
                                    fl = true;
                                if(fl)
                                    break;
                            }
                        }
                        if(fl)
                            break;
                    }
                    if(fl)
                        break;
                }
                cout << fl << endl;
            }
        }
    }
    return 0;
}