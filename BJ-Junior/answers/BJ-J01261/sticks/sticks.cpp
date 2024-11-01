#include<bits/stdc++.h>
using namespace std;
int func(int v){
    if(v==1 || v==0) return -1;
    if(v==2) return 1;
    if(v==3) return 7;
    if(v==4) return 4;
    if(v==5) return 2;
    if(v==6) return 6;
    if(v==7) return 8;
    if(v==8) return 18;
    if(v==9) return 24;
    if(v==10) return 22;
    if(v==11) return 20;
    if(v==12) return 28;
    if(v==13) return 68;
    if(v==14) return 88;
    if(v==15) return 108;
    if(v==16) return 188;
    if(v==17) return 200;
    if(v==18) return 208;
    if(v==19) return 288;
    if(v==20) return 688;
    if(v==21) return 888;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        int v;
        cin>> v;
        if(v<=21) cout<< func(v);
        else{
            string s;
            while(v>21){
                s+='8';
                v-=7;
            }
            cout<< func(v) << s;
        }
        cout<< endl;
    }
    return 0;
}
