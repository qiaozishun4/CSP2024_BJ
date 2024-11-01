#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[16]={0,2,5,5,4,5,6,3,7,6,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        for(ll i=1;i<=10;i++){
            if(a[i]==n){
                cout<<i;
                break;
            }

        }
        cout<<endl;
    }

    return 0;
}
