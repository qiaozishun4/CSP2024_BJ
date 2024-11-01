#include<bits/stdc++.h>
using namespace std;
long long t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n%2==1&&n<5&&n!=3){
            cout<<-1;
        }
        else if(n==3){
            cout<<7;
        }
        else if(n==6){
            cout<<6;
        }
        else if(n%2==0){
            for(int i=1;i<=n/2;i++){
                cout<<1;
            }
        }
        else{
            n-=5;
            for(int i=1;i<=n/2;i++){
                cout<<1;
            }
            cout<<2;

       }
        cout<<endl;
    }
    return 0;
}
