#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
int n,x,val[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        val[x]++;
    }
    sort(val+1,val+N,greater<>());
    cout<<val[1];
    return 0;
}
