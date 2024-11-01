#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    for(int i=upper_bound(a+1,a+n+1,a[1])-a;i<=n;i++){
        int j=upper_bound(a+1,a+n+1,a[i])-a;
        s+=min(j-i,i-1-s);
        i=j-1;
    }
    cout<<n-s;
    return 0;
}