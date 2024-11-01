#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],k;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>k;
        a[k]++;
    }long long ans=0;
    for(int i=1;i<=100000;i++){
        ans=max(ans,a[i]);
    }
    cout<<ans;
    return 0;
}
