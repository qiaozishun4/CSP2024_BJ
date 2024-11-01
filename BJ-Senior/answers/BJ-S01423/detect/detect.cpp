#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N],d[N],s[N],v0[N],f[N];
int main(){
   freopen("detect.in","r",stdin);
   freopen("detect.out","w",stdout);
    int t,n,m,l,v;
    cin >> t;
    for (int k = 1;k <= t;k++){
        int cnt1 = 0,cnt2 = 0;
        cin >> n >> m >> l >> v;
        for (int i = 1;i <= n;i++){
            cin >> s[i] >> v0[i] >> a[i];
            if (v0[i] > v) cnt1++;
        }
        for (int i = 1;i <= m;i++){
           cin >> d[i];
        }
        cout << cnt1 << " " << m - 1 << endl;
    }
    return 0;
}