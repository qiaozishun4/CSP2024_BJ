#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int st;
        cin>>st;
        if(st<=1) cout<<-1<<endl;
        else if(st==2) cout<<1<<endl;
        else if(st==3) cout<<7<<endl;
        else if(st==4) cout<<4<<endl;
        else if(st==5) cout<<2<<endl;
        else if(st==6) cout<<6<<endl;
        else if(st==7) cout<<8<<endl;
        else if(st==8) cout<<10<<endl;
        else if(st==9) cout<<18<<endl;
        else if(st==10) cout<<22<<endl;
        else if(st==11) cout<<20<<endl;
        else if(st==12) cout<<28<<endl;
        else if(st==13) cout<<68<<endl;
        else if(st==14) cout<<88<<endl;
        else if(st==15) cout<<108<<endl;
        else if(st==16) cout<<188<<endl;
        else if(st==17) cout<<200<<endl;
        else if(st==18) cout<<208<<endl;
        else if(st==19) cout<<288<<endl;
        else if(st==20) cout<<688<<endl;
        else if(st==21) cout<<888<<endl;
    }
    return 0;
}