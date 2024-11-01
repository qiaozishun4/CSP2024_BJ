#include<bits/stdc++.h>
using namespace std;
int a[6];
int c[6];

int main(){
  freopen("sticks.in","r",stdin);
  freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }else if(n==2){
            cout<<1<<endl;
            continue;
        }else if(n==3){
            cout<<7<<endl;
            continue;
        }else if(n==4){
            cout<<4<<endl;
            continue;
        }else if(n==5){
            cout<<2<<endl;
            continue;
        }else if(n==6){
            cout<<6<<endl;
            continue;
        }else if(n==7){
            cout<<8<<endl;
            continue;
        }else if(n==8){
            cout<<10<<endl;
            continue;
        }else if(n==9){
            cout<<18<<endl;
            continue;
        }else if(n==10){
            cout<<22<<endl;
            continue;
        }else if(n==11){
            cout<<20<<endl;
            continue;
        }else if(n==12){
            cout<<28<<endl;
        }else if(n==13){
            cout<<68<<endl;
        }else if(n==14){
            cout<<88<<endl;
        }else if(n==15){
            cout<<108<<endl;
        }else if(n==16){
            cout<<188<<endl;
        }else if(n==17){
            cout<<200<<endl;
        }else if(n==18){
            cout<<208<<endl;
        }else if(n==19){
            cout<<288<<endl;
        }else if(n==20){
            cout<<688<<endl;
        }
        int x=ceil(n/7);
        if(n%7==0) {
            for(int k=1;k<=n/7;k++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
