#include<bits/stdc++.h>
using namespace std;
void abc(){
    int n,f;
    cin>>n;
    f=n%7;
    if(f!=1){
        if(f==2)cout<<1;
        else if(f==3)cout<<7;
        else if(f==4)cout<<4;
        else if(f==5)cout<<2;
        else if(f==6)cout<<6;
        else cout<<8;
    }else if(n==1){
        cout<<-1;
    }
    cout<<endl;
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        abc();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
