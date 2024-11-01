#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    b[1] = 0;
    for(int i = 2;i<=100000;i++){
        b[i] = b[i-1]+a[i-1];
    }
    int ans = n;
    for(int i = 2;i<=100000;i++){
        ans-=min(a[i],b[i]);
        b[i+1]=b[i]+a[i]-min(a[i],b[i]);
    }
    cout<<ans;
    return 0;
}