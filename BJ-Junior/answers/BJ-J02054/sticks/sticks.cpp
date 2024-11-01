#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==1){
            cout<<10;
            n-=8;
        }else if(n%7==2){
            cout<<1;
            n-=2;
        }else if(n%7==3){
            cout<<22;
            n-=10;
        }else if(n%7==4){
            cout<<20;
            n-=11;
        }else if(n%7==5){
            cout<<2;
            n-=5;
        }else if(n%7==6){
            cout<<6;
            n-=6;
        }
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
