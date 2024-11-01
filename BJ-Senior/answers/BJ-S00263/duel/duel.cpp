#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[100001];
ll l=1;
ll ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++) cin >>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]>a[l] && i!=l) l++,ans++;
    }
    cout <<n-ans;
    return 0;
}
