#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a_[100010],b[100010],a[100010];
string d[20];
signed main(){
    freopen("arena.in","r",stdin);
    //freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a_[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }
    int K=0,K2=1;
    set<int> pow2;
    while(K2<n){
        pow2.insert(K2);
        K2*=2;
        K++;
    }
    pow2.insert(K2);
    for(int i=1;i<=K;i++){
        cin >> d[i];
    }
    int t;
    cin >> t;
    while(t--){
        int x[6]={};
        for(int i=0;i<=3;i++){
            cin >> x[i];
        }
        int tmp=0;
        for(int i=1;i<=n;i++){
            a[i]=a_[i]^x[i%4];
            tmp^=a[i];
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            ans+=i*tmp*b[i];
        }
        cout << ans << endl;
    }
    return 0;
}
