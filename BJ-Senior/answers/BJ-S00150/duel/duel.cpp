#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int ans=0,n,a[100007]={},l=0,r=1;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    while(r<n){
        if(a[l]<a[r]){
            r++;
            l++;
            ans++;
        }
        else{
            r++;
        }
    }
    cout<<n-ans;
    return 0;
}
