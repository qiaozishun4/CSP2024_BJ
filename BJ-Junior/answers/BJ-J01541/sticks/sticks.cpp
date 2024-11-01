#include<iostream>
using namespace std;
long long a,b[51],c[51],e[51];
int o[10]={6,2,5,5,4,5,6,3,7,6};
int d(int x,int y,int z){
    if(x==0&&y<=c[z]){
        c[z]=y;
        e[z]=1;
    }
    if(x>0){
        if(y!=0){
            for(int i=0;i<=9;i++){
                if(i!=3&&i!=5&&i!=6&&i!=9){
                    d(x-o[i],(y*10)+i,z);
                }
            }
        }else{
            for(int i=1;i<=9;i++){
                if(i!=3&&i!=5&&i!=9){
                    d(x-o[i],(y*10)+i,z);
                }
            }
        }
    }
    return 0;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i];
        c[i]=1000000;
        if(b[i]==21){
            c[i]=888;
            e[i]=1;
        }else{
            d(b[i],0,i);
        }
    }
    for(int i=1;i<=a;i++){
        if(e[i]==0){
            cout<<-1<<endl;
        }else{
            cout<<c[i]<<endl;
        }
    }
    return 0;
}
