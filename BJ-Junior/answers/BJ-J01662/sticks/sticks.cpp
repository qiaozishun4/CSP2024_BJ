#include<iostream>
using namespace std;
int a[10],T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
     cin>>T;
     a[2]=1;a[3]=7;a[4]=4;a[5]=2;a[6]=0;
     for(int i=1;i<=T;i++){
        int n;
        cin>>n;
        if(n==1){
            cout<<"-1";
        }else if(n>=7){
            int y=n%7;
            if(y==1){
                cout<<"10";
                for(int i=2;i<=n/7;i++){
                    cout<<'8';
                }
            }else if(y==2){
            cout<<'1';
            for(int i=2;i<=n/7;i++){
                cout<<'8';
            }
        }else if(y==3){
            cout<<"22";
            for(int i=3;i<=n/7;i++){
                cout<<'8';
            }

        }else if(y==4){
            cout<<a[5]<<a[6];
            for(int i=2;i<=n/7;i++){
                cout<<'8';
            }
        }else if(y==5){
            cout<<a[5];
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
        }else if(y==6){
            cout<<a[2]<<a[4];
            for(int i=2;i<=n/7;i++){
                cout<<'8';
            }

        }else{
            for(int i=1;i<=n/7;i++){
                cout<<'8';
            }
        }
        }else{
            if(n==2){
                cout<<a[2];
            }else if(n==3){
                cout<<a[3];
            }else if(n==4){
                cout<<a[4];
            }else if(n==5){
                cout<<a[5];
            }else if(n==6){
                cout<<'6';
            }
        }


     }




}
