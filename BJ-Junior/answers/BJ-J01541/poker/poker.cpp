#include<iostream>
using namespace std;
int a[4][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int b,d1,e1,z=52;
    string c;
    cin>>b;
    char d=c[0],e=c[1];
    for(int i=1;i<=b;i++){
        cin>>c;
        d=c[0];
        e=c[1];
        if(d=='D'){
            d1=1;
        }if(d=='C'){
            d1=2;
        }if(d=='H'){
            d1=3;
        }if(d=='S'){
            d1=4;
        }
        if(e=='A'){
            e1=1;
        }else if(e=='T'){
            e1=10;
        }else if(e=='J'){
            e1=11;
        }else if(e=='Q'){
            e1=12;
        }else if(e=='K'){
            e1=13;
        }else{
            e1=int(e-'0');
        }
        if(a[d1][e1]==0){
            z--;
        }
        a[d1][e1]=1;
    }
    cout<<z;
    return 0;
}
