#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        if(m<=1){
            cout<<-1;
        }else if(m==2){
            cout<<1;
        }else if(m==3){
            cout<<7;
        }else if(m==4){
            cout<<4;
        }else if(m==5){
            cout<<2;
        }else if(m==6){
            cout<<6;
        }else if(m==7){
            cout<<8;
        }else if(m==8){
            cout<<10;
        }else if(m==9){
            cout<<18;
        }else if(m==10){
            cout<<22;
        }else if(m==11){
            cout<<20;
        }else if(m==12){
            cout<<28;
        }else if(m==13){
            cout<<68;
        }else if(m==14){
            cout<<106;
        }else if(m==15){
            cout<<108;
        }else if(m==16){
            cout<<188;
        }else if(m==17){
            cout<<206;
        }else if(m==18){
            cout<<208;
        }else if(m==19){
            cout<<288;
        }else if(m==20){
            cout<<688;
        }
        cout<<endl;
    }
    return 0;
}
