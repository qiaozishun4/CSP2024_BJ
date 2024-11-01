#include<iostream>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n[55];
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n[i];
    }
    for(int i=0;i<t;i++){
        if(n[i]%7==0){
            for(int j=1;j<=n[i]%7;j++){
                cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}
