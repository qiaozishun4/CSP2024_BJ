#include<bits/stdc++.h>
using namespace std;
int a[100005]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=21;i<=n;i++){
            a[i]=a[i-7]*10+8;
        }
        cout<<a[n]<<endl;
    }
    return 0;
}
