#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int n,a[N];
ll f[N][2],ss[N];
inline void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++)ss[i]=ss[i-1]+(a[i]==a[i-1])*a[i];
    for(int i=1;i<=n;i++)f[i][0]=f[i][1]=0;
    for(int i=1;i<=n;i++){
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        for(int j=0;j<=i-2;j++){
            f[i][1]=max(f[i][1],f[j+1][1]+ss[i-1]-ss[j+1]+(a[i]==a[j])*a[i]);
        }
        //cerr<<f[i][0]<<' '<<f[i][1]<<endl;
    }
    cout<<max(f[n][0],f[n][1])<<'\n';
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
