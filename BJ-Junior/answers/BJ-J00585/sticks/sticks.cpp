#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,m[10]={6,2,5,5,4,5,6,3,7,6};
    cin>>t;
    for(int p=0;p<t;p++){
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        if(n<=7){
            if(n==2){
                cout<<"1"<<endl;
                continue;
            }
            if(n==3){
                cout<<"7"<<endl;
                continue;
            }
            if(n==4){
                cout<<"4"<<endl;
                continue;
            }
            if(n==5){
                cout<<"2"<<endl;
                continue;
            }
            if(n==6){
                cout<<"6"<<endl;
                continue;
            }
            if(n==7){
                cout<<"8"<<endl;
                continue;
            }
        }
        else{
            if(n%7==0){
                while(n>0){
                    n-=7;
                    cout<<'8';
                }
                cout<<endl;
                continue;
            }
            cout<<"208"<<endl;
        }
    }
    return 0;
}
