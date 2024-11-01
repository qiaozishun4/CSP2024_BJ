#include<bits/stdc++.h>
using namespace std;


main(){
    freopen("sticks1.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n[52],q[2],w[2],e[2],r[2],t[2],y[2],u[2],i[2],o[2],p[2];
    cin >>T;
    q[0]=0;
    q[1]=6;
    w[0]=1;
    w[1]=2;
    e[0]=2;
    e[1]=5;
    r[0]=3;
    r[1]=5;
    t[0]=4;
    t[1]=4;
    y[0]=5;
    y[1]=5;
    u[0]=6;
    u[1]=6;
    i[0]=7;
    i[1]=3;
    o[0]=8;
    o[1]=7;
    p[0]=9;
    p[1]=6;
    for(int i=0;i<T;i++){
        cin>>n[i];
        if(n[i]==1){
            cout <<-1;
        }
        if(n[i]==2){
            cout <<1;
        }
        if(n[i]==3){
            cout <<7;
        }
        if(n[i]==4){
            cout <<4;
        }
        if(n[i]==5){
            cout <<2;
        }
        if(n[i]==6){
            cout <<6;
        }
        if(n[i]==7){
            cout <<12;
        }
        if(n[i]==8){
            cout <<10;
        }
        if(n[i]==9){
            cout <<18;
        }
        if(n[i]==10){
            cout <<22;
        }
        if(n[i]==11){
            cout <<20;
        }
        if(n[i]==12){
            cout <<28;
        }
        if(n[i]==13){
            cout <<68;
        }
        if(n[i]==14){
            cout <<88;
        }
        if(n[i]==15){
            cout <<108;
        }
        if(n[i]==16){
            cout <<188;
        }
        if(n[i]==17){
            cout <<228;
        }
        if(n[i]==18){
            cout <<208;
        }
        if(n[i]==19){
            cout <<288;
        }
        if(n[i]==20){
            cout <<688;
        }
    }





    return 0;
}
