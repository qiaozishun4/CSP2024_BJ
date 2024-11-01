#include <iostream>
using namespace std;
bool ew[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,sum = 0;
    cin >>n;
    for(int i=0;i<n;i++){
        char c;
        char t;
        cin >>c;
        cin >>t;
        if(c=='D'){
            if(int('2')<=int(t)&&int(t)<=int('9')){
                ew[int(t)-int('0')] = 1;

            }else{
                if(t=='A') ew[1] = 1;
                if(t=='T') ew[10] = 1;
                if(t=='J') ew[11] = 1;
                if(t=='Q') ew[12] = 1;
                if(t=='K') ew[13] = 1;
            }
        }


        if(c=='C'){
            if(int('2')<=int(t)&&int(t)<=int('9')){
                ew[13+int(t)-int('0')] = 1;

            }else{
                if(t=='A') ew[1+13] = 1;
                if(t=='T') ew[10+13] = 1;
                if(t=='J') ew[11+13] = 1;
                if(t=='Q') ew[12+13] = 1;
                if(t=='K') ew[13+13] = 1;
            }
        }


        if(c=='H'){
            if(int('2')<=int(t)&&int(t)<=int('9')){
                ew[26+int(t)-int('0')] = 1;

            }else{
                if(t=='A') ew[1+26] = 1;
                if(t=='T') ew[26+10] = 1;
                if(t=='J') ew[26+11] = 1;
                if(t=='Q') ew[26+12] = 1;
                if(t=='K') ew[26+13] = 1;
            }
        }
        if(c=='S'){
            if(int('2')<=int(t)&&int(t)<=int('9')){
                ew[39+(t)-int('0')] = 1;

            }else{
                if(t=='A') ew[1+39] = 1;
                if(t=='T') ew[39+10] = 1;
                if(t=='J') ew[39+11] = 1;
                if(t=='Q') ew[39+12] = 1;
                if(t=='K') ew[39+13] = 1;
            }
        }
    }
    for(int i = 1;i<=52;i++){
        if(ew[i]==0) sum++;
    }
    cout <<sum;
    return 0;
}
