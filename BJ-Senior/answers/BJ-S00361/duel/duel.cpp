#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,l,r,mid,c[N];
inline void file(){freopen("duel.in","r",stdin),freopen("duel.out","w",stdout);}
inline bool check(int k){
    for(int i(1);i<=k;++i) if(c[i]==c[i+n-k]) return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> n;
    for(int i(1);i<=n;++i) cin >> c[i];
    sort(c+1,c+n+1);
    l=1,r=n-1;
    while(l<r){
        mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout << n-l << '\n';
    return 0;
}