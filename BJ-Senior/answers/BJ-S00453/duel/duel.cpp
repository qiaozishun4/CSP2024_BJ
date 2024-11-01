#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    int j=1,cnt=0;
    for(int i=2;i<=n;++i){
        if(a[i]!=a[j])++cnt,++j;
    }
    cout<<n-cnt<<'\n';
    return 0;
}