#include<iostream>
using namespace std;
int t,n;
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--) {
        cin>>n;
        if(n<7) {
            if(n==1) cout<<-1<<endl;
            if(n==2) cout<<1<<endl;
            if(n==3) cout<<7<<endl;
            if(n==4) cout<<4<<endl;
            if(n==5) cout<<2<<endl;
            if(n==6) cout<<6<<endl;
        }
        else {
            int a=n/7-1,b=n%7+7;
            if(b==7) cout<<8;
            if(b==8) cout<<10;
            if(b==9) cout<<18;
            if(b==10) cout<<22;
            if(b==11) cout<<20;
            if(b==12) cout<<28;
            if(b==13) cout<<68;
            for(int i=1;i<=a;i++) cout<<8;
            cout<<endl;
        }
    }
    return 0;
}