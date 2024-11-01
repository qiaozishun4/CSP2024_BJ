#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool f[100010];
bool g[100010];
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int c = 2;
    int h = n;
    for (int i=1;i<=n;i++) {
        bool flag = true;
        for (int j=c;j<=n;j++) {
            if (a[j] > a[i] && !f[j]) {
                f[j] = true;
                g[i] = true;
                h--;
                flag = false;
                c = j+1;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    cout << h;
    return 0;
}
