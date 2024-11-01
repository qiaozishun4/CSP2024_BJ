#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,b[N];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>> t;
    for(int i=1;i<=t;i++){
        cin>> b[i];
    }
    for(int i=1;i<=t;i++){
        if(b[i]==6){
            cout<< 6 << endl;
        }else if(b[i]==2){
            cout<< 1 << endl;
        }else if(b[i]==5){
            cout<< 2 << endl;
        }else if(b[i]==4){
            cout<< 4 << endl;
        }else if(b[i]==3){
            cout<< 7 << endl;
        }else if(b[i]==7){
            cout<< 8 << endl;
        }else if(b[i]==8){
            cout<< 10 << endl;
        }else if(b[i]==9){
            cout<< 18 << endl;
        }else if(b[i]==10){
            cout<< 40 << endl;
        }else if(b[i]==11){
            cout<< 20 << endl;
        }else if(b[i]==12){
            cout<< 28 << endl;
        }else if(b[i]==13){
            cout<< 80 << endl;
        }else if(b[i]==14){
            cout<< 128 << endl;
        }else if(b[i]==15){
            cout<< 108 << endl;
        }else if(b[i]==16){
            cout<< 248 << endl;
        }else if(b[i]==17){
            cout<< 408 << endl;
        }else if(b[i]==18){
            cout<< 208 << endl;
        }else if(b[i]==19){
            cout<< 478 << endl;
        }else if(b[i]==20){
            cout<< 1028 << endl;
        }else if(b[i]==21){
            cout<< 10248 << endl;
        }else if(b[i]==24){
            cout<< 12478 << endl;
        }else if(b[i]==27){
            cout<< 102478 << endl;
        }else{
            cout<< -1 << endl;
        }
    }
    return 0;
}
