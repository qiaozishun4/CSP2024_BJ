#include<iostream>
using namespace std;
int n,a[100001],b[100001],minn=100001,ans;
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=100000;i++) {
        ans-=min(ans,b[i]);
        ans+=b[i];
    }
    cout<<ans<<endl;
    return 0;
}