#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000009];
bool u[1000009];
signed main(){
    std::ios::sync_with_stdio(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int z;
    z=1;
    int ans;
    ans=n;
    for(int i=1;i<=n;i++){
        while(z<=n&&(a[z]<=a[i]||u[z])){
            ++z;
        }
        if(z!=n+1){
            u[z]=1;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
