#include <bits/stdc++.h>
using namespace std;
int esyn[21]{0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n<=20){
            cout<<esyn[n]<<endl;
        }
        else if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<"8";
            }
            cout<<endl;
        }
        else if(n%7==1){
            cout<<"10";
            for(int j=1;j<=n/7-1;j++){
                cout<<"8";
            }
            cout<<endl;
        }
        else cout<<"-1"<<endl;
    }
    return 0;
}
