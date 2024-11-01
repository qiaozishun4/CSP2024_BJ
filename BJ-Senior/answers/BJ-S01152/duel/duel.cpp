#include <bits/stdc++.h>
using namespace std;
int a[100005];
int t;
int ans;
int n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //next_permutation();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        a[t]++;
        ans=max(ans,a[t]);
    }
    cout<<ans<<endl;
    return 0;
}
