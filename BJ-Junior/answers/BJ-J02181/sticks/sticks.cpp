#include<bits/stdc++.h>
using namespace std;
int n,t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
        }
        else if((n-1)%7==0){
            cout<<1;
            for(int i=1;i<=(n-1)/7;i++){
                cout<<8;
            }
        }
        else cout<<0;
    }
    return 0;
}
