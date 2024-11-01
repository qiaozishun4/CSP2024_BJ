#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    int i;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }else if(n==2){
            cout<<1<<endl;
            continue;
        }else if(n==3){
            cout<<7<<endl;
            continue;
        }else if(n==4){
            cout<<4<<endl;
            continue;
        }else if(n==5){
            cout<<2<<endl;
            continue;
        }else if(n==6){
            cout<<6<<endl;
            continue;
        }else if(n==7){
            cout<<8<<endl;
            continue;
        }else if(n==8){
            cout<<10<<endl;
            continue;
        }else if(n==9){
            cout<<18<<endl;
            continue;
        }else if(n==10){
            cout<<22<<endl;
            continue;
        }else if(n==11){
            cout<<20<<endl;
            continue;
        }else if(n==12){
            cout<<28<<endl;
            continue;
        }else if(n==13){
            cout<<68<<endl;
            continue;
        }else if(n==14){
            cout<<88<<endl;
            continue;
        }else if(n==15){
            cout<<108<<endl;
            continue;
        }else if(n==16){
            cout<<188<<endl;
            continue;
        }else if(n==17){
            cout<<228<<endl;
            continue;
        }else if(n==18){
            cout<<208<<endl;
            continue;
        }else if(n==19){
            cout<<288<<endl;
            continue;
        }else if(n==20){
            cout<<688<<endl;
            continue;
        }
        if(n%7==0){
            for(i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            cout<<10;
            for(i=1;i<(n-1)/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}
