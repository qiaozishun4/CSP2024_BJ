#include <bits/stdc++.h>
using namespace std;

bool myflag[150][150];

int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans = 52;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!myflag[s[0]][s[1]]) {
            myflag[s[0]][s[1]] = true;
            ans --;
        }
    }
    cout << ans << endl;
    return 0;
}