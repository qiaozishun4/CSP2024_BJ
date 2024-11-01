#include<iostream>
using namespace std;
int m;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>m;
        if(m%7==0){
            for(int i=1;i<=m/7;i++)cout<<8;
            cout<<endl;
            continue;
        }
        else if(m==1){
            cout<<-1<<endl;
            continue;
        }
        else if(m==2){
            cout<<1<<endl;
            continue;
        }
        else if(m==3){
            cout<<7<<endl;
            continue;
        }
        else if(m==4){
            cout<<4<<endl;
            continue;
        }
        else if(m==5){
            cout<<2<<endl;
            continue;
        }
        else if(m==6){
            cout<<6<<endl;
            continue;
        }
        else if(m==7){
            cout<<8<<endl;
            continue;
        }
        else if(m==8){
            cout<<10<<endl;
            continue;
        }
        else if(m==9){
            cout<<18<<endl;
            continue;
        }
        else if(m==10){
            cout<<22<<endl;
            continue;
        }
        else if(m==11){
            cout<<20<<endl;
            continue;
        }
        else if(m==12){
            cout<<28<<endl;
        }
        else if(m==13){
            cout<<68<<endl;
            continue;
        }
        else if(m==14){
            cout<<88<<endl;
            continue;
        }
        else if(m==15){
            cout<<108<<endl;
            continue;
        }
        else if(m==16){
            cout<<188<<endl;
            continue;
        }
        else if(m==17){
            cout<<228<<endl;
            continue;
        }
        else if(m==18){
            cout<<208<<endl;
            continue;
        }
        else if(m==19){
            cout<<288<<endl;
            continue;
        }
        else if(m==20){
            cout<<688<<endl;
            continue;
        }
        else cout<<6888<<endl;
    }
    return 0;
}
