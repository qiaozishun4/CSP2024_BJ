#include <bits/stdc++.h>
using namespace std;
int bj[18]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<'\n';
            continue;
        }
        string ans="";
        while(n){
            if(n>17){
                ans+='8';
                n-=7;
            }
            else {
                cout<<bj[n];
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
