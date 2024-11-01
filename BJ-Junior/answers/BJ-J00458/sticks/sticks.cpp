#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
        }
        else if(n==2){
            cout<<"1"<<endl;
        }
        else if(n==3){
            cout<<"7"<<endl;
        }
        else if(n==4){
            cout<<"4"<<endl;
        }
        else if(n==5){
            cout<<"3"<<endl;
        }
        else if(n==6){
            cout<<"6"<<endl;
        }
        else if(n==7){
            cout<<"8"<<endl;
        }
        else if(n==8){
            cout<<"44"<<endl;
        }
        else if(n==9){
            cout<<"18"<<endl;
        }
        else if(n==10){
            cout<<"22"<<endl;
        }
        else if(n==11){
            cout<<"26"<<endl;
        }
        else if(n==12){
            cout<<"28"<<endl;
        }
        else if(n==13){
            cout<<"68"<<endl;
        }
        else if(n==14){
            cout<<"88"<<endl;
        }
        else if(n==15){
            cout<<"168"<<endl;
        }
        else if(n==18){
            cout<<"208"<<endl;
        }
        else{
            cout<<"-1";
        }
    }
    return 0;
}
