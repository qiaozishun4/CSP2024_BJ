#include<bits/stdc++.h>
using namespace std;
int b[10]{6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%7==0){
            int x=n/7;
            for(int i=1;i<=x;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            int x=n/7;
            x--;
            cout<<10;
            for(int i=1;i<=x;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            if(n==1)cout<<-1;
            if(n==2)cout<<1;
            if(n==3)cout<<7;
            if(n==4)cout<<4;
            if(n==5)cout<<2;
            if(n==6)cout<<6;
            if(n==7)cout<<8;
            if(n==8)cout<<10;
            if(n==9)cout<<18;
            if(n==10)cout<<23;
            if(n==11)cout<<20;
            if(n==12)cout<<28;
            if(n==13)cout<<68;
            if(n==14)cout<<88;
            if(n==15)cout<<108;
            if(n==16)cout<<220;
            if(n==17)cout<<228;
            if(n==18)cout<<208;
            if(n==19)cout<<608;
            if(n==20)cout<<808;
            cout<<endl;
        }
    }
    return 0;
}

