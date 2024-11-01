#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> aa(n);
    for(int i=0;i<n;i++){
        cin >> aa[i];
    }
    vector<int> c(m);
    for(int i=0;i<m;i++){
        cin >> c[i];
    }
    int k;
    for(int i=1;2*i<=n;i++){
        k=i;
    }
    k--;
    vector<vector<char>> K(k,vector<char>(k));
    int T;
    cin >> T;
    while(T--){
        vector<int> x(4);
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        vector<int> a(n);
        for(int i=0;i<n;i++){
            a[i]=aa[i]^x[i%4];
        }
        for(int i=0;i<m;i++){
            int j=1;
            while(2*j<=)
        }
    }
    return 0;
}
