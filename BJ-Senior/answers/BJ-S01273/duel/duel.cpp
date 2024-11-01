#include<bits/stdc++.h>
using namespace std;
int n,a[100005],q[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=100000;i++){
        q[i]=a[i]+q[i-1];
    }
    int ans=0;
    for(int i=1;i<=100000;i++){
        ans=ans+min(q[i]-a[i],a[i]);
    }
    cout<<n-ans;
}
