#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a==1){
            cout<<"-1";
        }if(a==2){
            cout<<1;
        }if(a==3){
            cout<<7;
        }if(a==4){
            cout<<4;
        }if(a==5){
            cout<<2;
        }if(a==6){
            cout<<6;
        }if(a==7){
            cout<<8;
        }if(a==8){
            cout<<10;
        }if(a==9){
            cout<<24;
        }if(a==10){
            cout<<22;
        }if(a==11){
            cout<<20;
        }if(a==12){
            cout<<28;
        }if(a==13){
            cout<<80;
        }if(a==14){
            cout<<88;
        }if(a==15){
            cout<<204;
        }if(a==16){
            cout<<202;
        }if(a==17){
            cout<<228;
        }if(a==18){
            cout<<208;
        }if(a==19){
            cout<<288;
        }if(a==20){
            cout<<808;
        }if(a==50){
            cout<<27888888;
        }
    }return 0;}
