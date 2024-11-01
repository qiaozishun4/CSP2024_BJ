#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,r[100005],f[100005],maxf;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>r[i];
        f[r[i]]++;
    }
    for(ll i=1;i<=100000;i++){
        maxf=max(maxf,f[i]);
    }
    cout<<maxf;
    return 0;
}
