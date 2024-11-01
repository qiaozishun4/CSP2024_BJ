#include<bits/stdc++.h>
using namespace std;
string s[100010];
bool flag[200010];
int a[100010], b[100010];

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        memset(flag, false, sizeof(flag));
        int n, k, q;
        cin >> n >> k >> q;
        for (int j = 1; j <= n; j++){
            cin >> b[j];
            for (int k = 1; k <= b[j]; k++){
                cin >> a[k];
                flag[a[k]] = true;
            }
        }
        int r, c;
        if (!flag[c]){
            cout << 0 << '\n';
            continue;
        }
        else{
            cout << 1 << '\n';
            continue;
        }
    }

    return 0;
}
