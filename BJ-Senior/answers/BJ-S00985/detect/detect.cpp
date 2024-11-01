#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N=1e3+10;
int n;
int a[MAX_N],b[MAX_N],mp[MAX_N],sum[MAX_N];
long double m[MAX_N];
void solve(){
    bool mps[MAX_N]={false};
    int ms ,L ,V,ans=0;
    cin >> n >> ms >> L >> V;
    for(int i=1;i<=n;i++){
        cin >> m[i] >> b[i] >> a[i];
    }
    for(int i=1;i<=ms;i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(int i=1;i<=L;i++){
        sum[i]+=sum[i-1]+mp[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>=0){
            while(m[i]<L&&b[i]<V){
                m[i]+=b[i]+double(a[i]/2);
                b[i]+=a[i];
            }
        }
        if(b[i]>V){
            if(sum[int(m[i]+0.99)]-sum[L]){
                mps[i]=true;
                ans++;
            }
        }
    }
    cout << ans;

}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}