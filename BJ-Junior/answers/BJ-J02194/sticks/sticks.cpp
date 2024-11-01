#include<iostream>
using namespace std;
int a[15]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int shu;
        cin>>shu;
        if(shu<=13){
            cout<<a[shu]<<endl;
        }else{
            if(shu%7==0){
                for(int j=0;j<(shu/7);j++){
                    cout<<8;
                }
            }else if(shu%7==1){
                cout<<10;
                for(int j=0;j<(shu/7)-1;j++){
                    cout<<8;
                }
            }else if(shu%7==2){
                cout<<1;
                for(int j=0;j<(shu/7);j++){
                    cout<<8;
                }
            }else if(shu%7==3){
                cout<<200;
                for(int j=0;j<(shu/7)-2;j++){
                    cout<<8;
                }
            }else if(shu%7==4){
                cout<<20;
                for(int j=0;j<(shu/7)-1;j++){
                    cout<<8;
                }
            }else if(shu%7==5){
                cout<<2;
                for(int j=0;j<(shu/7);j++){
                    cout<<8;
                }
            }else{
                cout<<6;
                for(int j=0;j<(shu/7);j++){
                    cout<<8;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}