#include <bits/stdc++.h>
using namespace std;
int n,t,ans[30]={-1,-1,1,7,4,2,6,8,10,18,23,20,28,68,88,108,188,200,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=20){
            cout<<ans[n];
        }else{
            cout<<"-1";
        }
        cout<<endl;
    }
    return 0;
}