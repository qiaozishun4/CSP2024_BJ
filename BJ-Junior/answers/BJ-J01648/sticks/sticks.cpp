#include<iostream>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    int b[15]={6,2,5,5,4,5,6,3,7,6};
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a==1){
            cout<<-1<<endl;
            continue;
        }
        if(a==2){
            cout<<1<<endl;
            continue;
        }
        if(a==3){
            cout<<7<<endl;
            continue;
        }
        if(a==4){
            cout<<4<<endl;
            continue;
        }
        if(a==5){
            cout<<2<<endl;
            continue;
        }
        if(a==6){
            cout<<6<<endl;
            continue;
        }
        if(a==7){
            cout<<8<<endl;
            continue;
        }
        if(a%7==0){
            for(int j=1;j<=a/7;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        int geshu=a/7+1;
        int geshu1=geshu;
        for(int j=1;j<=geshu1;j++){
            if(j==1){
                for(int z=1;z<=9;z++){
                    if((a-b[z])<=(geshu-1)*7){
                        cout<<z;
                        a=a-b[z];
                        geshu--;
                        break;
                    }
                }
            }else{
                for(int z=0;z<=9;z++){
                    if((a-b[z])<=(geshu-1)*7){
                        cout<<z;
                        a=a-b[z];
                        geshu--;
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

