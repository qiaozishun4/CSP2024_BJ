#include<iostream>
using namespace std;
int f[]={-1,1,7,4,2,6,8,10,18,23,20,28,68,88,108,188,200,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n<=20){
            cout<<f[n-1]<<endl;
        }
        else if(n%7==0){
            for(int j=0;j<n/7;j++){
                cout<<'8';
            }
        }
        else if(n%7==1){
            cout<<'10';
            for(int j=1;j<n/7;j++){
                cout<<'8';
            }
        }
        else if(n%7==2){
            cout<<'1';
            for(int j=0;j<n/7;j++){
                cout<<'8';
            }
        }
        else if(n%7==3){
            cout<<'200';
            for(int j=2;j<n/7;j++){
                cout<<'8';
            }
        }
        else if(n%7==4){
            cout<<'20';
            for(int j=1;j<n/7;j++){
                cout<<'8';
            }
        }
        else if(n%7==5){
            cout<<'2';
            for(int j=0;j<n/7;j++){
                cout<<'8';
            }
        }
        else if(n%7==6){
            cout<<'6';
            for(int j=0;j<n/7;j++){
                cout<<'8';
            }
        }
    }
    return 0;
}
