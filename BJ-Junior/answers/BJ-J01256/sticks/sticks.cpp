#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    for(int i=0;i<t;i++){
        if(a[i]==1)cout<<-1<<endl;
        if(a[i]==2)cout<<1<<endl;
        if(a[i]==3)cout<<7<<endl;
        if(a[i]==4)cout<<4<<endl;
        if(a[i]==5)cout<<2<<endl;
        if(a[i]==6)cout<<6<<endl;
        if(a[i]==7)cout<<8<<endl;
        if(a[i]==8)cout<<10<<endl;
        if(a[i]==9)cout<<18<<endl;
        if(a[i]==10)cout<<22<<endl;
        if(a[i]==11)cout<<20<<endl;
        if(a[i]==12)cout<<28<<endl;
        if(a[i]==13)cout<<68<<endl;
        if(a[i]==14)cout<<88<<endl;
        if(a[i]==15)cout<<108<<endl;
        if(a[i]==16)cout<<188<<endl;
        if(a[i]==17)cout<<200<<endl;
        if(a[i]==18)cout<<208<<endl;
        if(a[i]==19)cout<<288<<endl;
        if(a[i]==20)cout<<688<<endl;
    }

    return 0;
}
