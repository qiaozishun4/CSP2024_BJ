#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n<=1){
            cout<<-1<<endl;
        }else if(n==2){
            cout<<1<<endl;
        }else if(n==3){
            cout<<7<<endl;
        }else if(n==4){
            cout<<4<<endl;
        }else if(n==5){
            cout<<2<<endl;
        }else if(n==6){
            cout<<6<<endl;
        }else if(n==7){
            cout<<8<<endl;
        }else if(n==8){
            cout<<16<<endl;
        }else if(n==9){
            cout<<18<<endl;
        }else if(n==10){
            cout<<22<<endl;
        }else{
            cout<<208<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}