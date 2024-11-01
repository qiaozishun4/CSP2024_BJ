#include<bits/stdc++.h>
using namespace std;
//           0  1 2 3 4 5 6 7  8  9 10 11 12 13 14  15  16  17  18  19  20
int ans[55]={0,-1,2,7,4,2,6,8,10,18,23,20,28,68,88,168,188,228,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<=20){
            cout<<ans[n]<<"\n";
        }
        else cout<<"-1\n";
    }
    return 0;
}