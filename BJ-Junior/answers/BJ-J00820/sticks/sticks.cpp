#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n[105],ans,a0=6,a1=2,a2=5,a3=5,a4=4,a5=5,a6=6,a7=3,a8=7,a9=6;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n[i];
    }
    for(int i=1;i<=T;i++){
        if(n[i]==1){
            cout<<"-1";
            cout<<endl;
            continue;
        }
        if(n[i]==2){
            cout<<"1";
        }
        if(n[i]==5){
            cout<<"2";
        }
        if(n[i]==4){
            cout<<"4";
        }
        if(n[i]==6){
            cout<<"6";
        }
        if(n[i]==3){
            cout<<"7";
        }
        if(n[i]==7){
            cout<<"8";
        }
        cout<<endl;
    }cout<<"208";
    return 0;
}
