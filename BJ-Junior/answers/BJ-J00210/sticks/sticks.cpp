#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[]={-1,-1,1,7,4,2,6,8,10,18,22,26,28,68,88,108,188,228,208,288,688};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        cout<<a[n]<<'\n';
    }
    return 0;
}
