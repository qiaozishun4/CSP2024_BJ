#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int b=1;b<=n;b++){
        long long x;
        cin>>x;
        a[x]++;
        ans=max(ans,a[x]);
    }
    cout<<ans;
    return 0;
}
