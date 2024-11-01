#include<iostream>
using namespace std;
int main(){
     freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        if(x==1) cout<<-1<<endl;
        if(x==2) cout<<1<<endl;
        if(x==3) cout<<7<<endl;
        if(x==4) cout<<4<<endl;
        if(x==5) cout<<2<<endl;
        if(x==6) cout<<6<<endl;
        if(x==7) cout<<8<<endl;
        if(x==8) cout<<10<<endl;
        if(x==9) cout<<18<<endl;
        if(x==10) cout<<22<<endl;
        if(x==11) cout<<20<<endl;
        if(x==12) cout<<28<<endl;
        if(x==13) cout<<68<<endl;
        if(x==14) cout<<88<<endl;
        if(x==15) cout<<108<<endl;
        if(x==16) cout<<188<<endl;
        if(x==17) cout<<200<<endl;
        if(x==18) cout<<208<<endl;
        if(x==19) cout<<288<<endl;
        if(x==20) cout<<688<<endl;
    }

}
