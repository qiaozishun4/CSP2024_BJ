#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        if(m%7==0){
            for(int i=1;i<=m/7;i++){
                cout<<8;
            }
        }
        if(m==1) cout<<-1;
        if(m==2) cout<<1;
        if(m==3) cout<<7;
        if(m==4) cout<<4;
        if(m==5) cout<<2;
        if(m==6) cout<<6;
        if(m==8) cout<<16;
        if(m==9) cout<<18;
        if(m==10) cout<<22;
        if(m==11) cout<<20;
        if(m==12) cout<<28;
        if(m==13) cout<<68;
        if(m==15) cout<<108;
        if(m==16) cout<<188;
        if(m==17) cout<<200;
        if(m==18) cout<<208;
        if(m==19) cout<<288;
        if(m==20) cout<<688;
        if(m==22) cout<<1088;
        if(m==23) cout<<1888;
        if(m==24) cout<<2008;
        if(m==25) cout<<2088;
        if(m==26) cout<<2888;
        if(m==27) cout<<6888;
        if(m==29) cout<<10888;
        if(m==30) cout<<18888;
        if(m==31) cout<<20088;
        if(m==32) cout<<20888;
        if(m==33) cout<<28888;
        if(m==34) cout<<68888;
        if(m==36) cout<<108888;
        if(m==37) cout<<188888;
        if(m==38) cout<<200888;
        if(m==39) cout<<208888;
        if(m==40) cout<<288888;
        if(m==41) cout<<688888;
        if(m==43) cout<<1088888;
        if(m==44) cout<<1888888;
        if(m==45) cout<<2008888;
        if(m==46) cout<<2088888;
        if(m==47) cout<<2888888;
        if(m==48) cout<<6888888;
        if(m==50) cout<<10888888;
        if(m==51) cout<<18888888;
        if(m==52) cout<<20088888;
        if(m==53) cout<<20888888;
        if(m==54) cout<<28888888;
        if(m==55) cout<<68888888;
        if(m==57) cout<<108888888;
        if(m==58) cout<<188888888;
        if(m==59) cout<<200888888;
        if(m==60) cout<<208888888;
        if(m==61) cout<<288888888;
        if(m==62) cout<<688888888;
        if(m==64) cout<<"1088888888";
        if(m==65) cout<<"1888888888";
        if(m==66) cout<<"2008888888";
        if(m==67) cout<<"2088888888";
        if(m==68) cout<<"2888888888";
        if(m==69) cout<<"6888888888";
        cout<<endl;
    }
    return 0;
}
