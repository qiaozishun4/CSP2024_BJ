#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int t,n,ans,a[N],f[N][N];
inline void file(){freopen("color.in","r",stdin),freopen("color.out","w",stdout);}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> t;
    while(t--){
        cin >> n,ans=0,memset(f,0,sizeof(f));
        for(int i(1);i<=n;++i) cin >> a[i];
        for(int i(2);i<=n;++i) for(int j(1);j<i-1;++j) f[i][j]=f[i-1][j]+(a[i]==a[i-1])*a[i],f[i][i-1]=max(f[i][i-1],f[i-1][j]+(a[i]==a[j])*a[i]);
        for(int i(1);i<n;++i) ans=max(ans,f[n][i]);
        cout << ans << '\n';
    }
    return 0;
}