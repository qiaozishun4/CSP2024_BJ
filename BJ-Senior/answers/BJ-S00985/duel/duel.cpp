#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
ll v[int(1e6+10)],n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    sort(v+1,v+n+1);
    ll old=1;
    for(int i=1;i<=n;i++){
        if(v[old]!=v[i]){
            old++;
        }
    }
    cout << n-old+1;
    return 0;
}