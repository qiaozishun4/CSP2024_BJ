#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100005;
int n, sze, ans, x;
int a[MAXN];

bool cmp(int a, int b){
    return a >b;
}

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> x;
        if(!a[x])
            ++sze;
        ++a[x];
    }
    sort(a+1, a+100004, cmp);
    while(sze > 1){
        for(int i = 1; a[i]; i ++){
            --a[i];
            if(!a[i])
                --sze;
        }
        ++ans;
    }
    cout << ans + a[1] << endl;
    return 0;
}
