#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long db[10000]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,60,88,108,188,228,208,288,688,888,1088,1888,2008,2088,2888,6888,8888};
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k>28){
            if(k%7==0){
                for(int i=0;i<k/7;i++) cout<<8;
            }else if(k%7==1){
                cout<<10;
                for(int i=0;i<k/7-1;i++) cout<<8;
            }else if(k%7==2){
                cout<<1;
                for(int i=0;i<k/7;i++) cout<<8;
            }else if(k%7==3){
                cout<<200;
                for(int i=0;i<k/7-2;i++) cout<<8;
            }else if(k%7==4){
                cout<<20;
                for(int i=0;i<k/7-1;i++) cout<<8;
            }else if(k%7==5){
                cout<<2;
                for(int i=0;i<k/7;i++) cout<<8;
            }else{
                cout<<6;
                for(int i=0;i<k/7;i++) cout<<8;
            }
        }else cout<<db[k]<<endl;
    }
    fclose(stdout);
    fclose(stdin);
}
