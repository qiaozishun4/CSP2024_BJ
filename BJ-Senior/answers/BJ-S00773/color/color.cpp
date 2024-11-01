#include<bits/stdc++.h>
using namespace std;
int n=0,a[100005];
int lefts(int k,int l){
    if(k<1)return 0;
    if(a[k]==a[l])return a[k];
    return lefts(k-1,l);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int ci;cin>>ci;
    while(ci--){
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=2;i<=n;i++){
            ans+=lefts(i-1,i);
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
