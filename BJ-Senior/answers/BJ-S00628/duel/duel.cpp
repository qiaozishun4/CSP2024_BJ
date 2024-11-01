#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +5;

int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out", "w", stdout);
    int n, a[N];
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int liv = n;
    int maxx = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] >= maxx) {
            maxx = a[i];
            for(int j = 0 ; j <= i; j ++) {
                if(a[j] < maxx && a[j] != -1){
                    a[j] = -1;
                    liv --;
                    break;
                }
            }
        }
    }
    cout << liv;
    return 0;
}
