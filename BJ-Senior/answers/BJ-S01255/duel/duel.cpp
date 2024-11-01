#include <iostream>
#include <stack>
using namespace std;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int cnt[(int)1e5+2];
    for(int i=0; i<=1e5; i++) cnt[i] = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int ans = -1;
    for(int i=1; i<=1e5; i++) {
        if(ans < cnt[i]) ans = cnt[i];
    }
    cout << ans << endl;
    return 0;
}
