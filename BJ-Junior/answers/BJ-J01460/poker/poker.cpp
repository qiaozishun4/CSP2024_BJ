#include <bits/stdc++.h>
using namespace std;

int n;

string k[55];
int ans = 0;

string s;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> s;
        bool pd=1;
        for(int j = 1; j <= ans; j++) {
            if(s == k[j]){
                 pd=0;j=ans+1;
            }
        }
        if(pd) {
            ans++;
            k[ans] = s;
        }

    }
    cout << 52 - ans << endl;
    return 0;
}
