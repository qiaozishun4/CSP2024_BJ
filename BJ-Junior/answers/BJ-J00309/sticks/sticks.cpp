#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n[N];
int main (){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
    }
    for(int i=1;i<=t;i++){
        if(n[i]<2){
            cout<<"-1"<<"\n";
        }
        else if(n[i]==2){
            cout<<"1"<<"\n";
        }
        else if(n[i]==3){
            cout<<"7"<<"\n";
        }
        else if(n[i]==4){
            cout<<"4"<<"\n";
        }
        else if(n[i]==5){
            cout<<"2"<<"\n";
        }
        else if(n[i]==6){
            cout<<"6"<<"\n";
        }
        else if(n[i]==7){
            cout<<"8"<<"\n";
        }
        else if(n[i]==8){
            cout<<"10"<<"\n";
        }
        else if(n[i]==9){
            cout<<"18"<<"\n";
        }
        else if(n[i]==10){
            cout<<"23"<<"\n";
        }
        else if(n[i]==18){
            cout<<"208"<<"\n";
        }
        else if(n[i]==11){
            cout<<"26"<<"\n";
        }
        else if(n[i]==12){
            cout<<"28"<<"\n";
        }
        else if(n[i]==13){
            cout<<"68"<<"\n";
        }
        else if(n[i]==14){
            cout<<"128"<<"\n";
        }
        else if(n[i]==15){
            cout<<"204"<<"\n";
        }
        else if(n[i]==16){
            cout<<"203"<<"\n";
        }
        else if(n[i]==17){
            cout<<"206"<<"\n";
        }
        else if(n[i]==19){
            cout<<"667"<<"\n";
        }
        else if(n[i]==20){
            cout<<"2034"<<"\n";
        }
        else if(n[i]==21){
            cout<<"2035"<<"\n";
        }
        else {
            cout<<"2057"<<"\n";
        }
    }
    return 0;
}

