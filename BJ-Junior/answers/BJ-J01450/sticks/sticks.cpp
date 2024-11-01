#include<iostream>
using namespace std;
int a[51];
unsigned long long stick(int n){
    if(n==1){
        cout<<-1<<endl;
        return;
    }else{
        if(n==2){
            return 1;
        }else if(n==3){
            return 7;
        }else if(n==4){
            return 4;
        }else if(n==5){
            return 2;
        }else if(n==6){
            return 6;
        }else if(n==7){
            return 8;
        }else if(n==8){
            return 10;
        }else if(n==9){
            return 18;
        }else if(n==10){
            return 22;
        }else if(n==11){
            return 20;
        }else if(n==12){
            return 28;
        }else if(n==13){
            return 68;
        }else if(n==14){
            return 88;
        }else if(n==15){
            return 108;
        }else if(n==16){
            return 188;
        }else if(n==17){
            return 200;
        }else if(n==18){
            return 208;
        }else if(n==19){
            return 288;
        }else if(n==20){
            return 688;
        }else if(n==21){
            return 888;
        }else{
            return sticks(n-7)*10+8;
        }
    }

}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<sticks(a[i]);
    }
    return 0;
}
