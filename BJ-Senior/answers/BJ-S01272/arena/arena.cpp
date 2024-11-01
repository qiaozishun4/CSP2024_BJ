#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N], c[N];
int minn[N];

int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> c[i];
    }
    int tmp = n;
    int k;
    while(tmp){
        if(tmp-lowbit(tmp) == 0){
            k = lowbit(tmp);
        }
        tmp-=lowbit(tmp);
    }
    if(n != k) k<<=1;
    tmp = k; k = 0;
    while(tmp & 1 == 0){
        k++;
        tmp >>= 1;
    }
    for(int i=1;i<=k;i++){
        string s;
        cin >> s;
    }
    int T; cin >> T;
    while(T--){
        int x[4];
        for(int i=0;i<4;i++) cin >> x[i];
        minn[1] = a[1]^x[1];
        for(int i=2;i<=n;i++){
            minn[i] = min(a[i]^x[i%4], minn[i-1]);
        }
        long long ans = 0;
        for(int i=1;i<=m;i++){
            ans ^= 1LL*i*minn[i];
        }
        cout << ans << '\n';
    }
    return 0;
}