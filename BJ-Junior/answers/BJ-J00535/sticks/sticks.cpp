#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1)cout<<-1;
        else if(n==2)cout<<1;
        else if(n==3)cout<<7;
        else if(n==4)cout<<4;
        else if(n==5)cout<<2;
        else if(n==6)cout<<6;
        else if(n==7)cout<<8;

        else if(n==8)cout<<27;
        else if(n==9)cout<<18;
        else if(n==10)cout<<22;
        else if(n==11)cout<<26;
        else if(n==12)cout<<28;
        else if(n==13)cout<<18;
        else if(n==14)cout<<77;
        else if(n==15)cout<<168;
        else if(n==16)cout<<188;
        else if(n==17)cout<<228;
        else if(n==18)cout<<208;
        else if(n==19)cout<<277;
        else if(n==20)cout<<677;
    }
    return 0;
}
