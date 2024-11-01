#include<bits/stdc++.h>
using namespace std;
int u[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<'\n';
            continue;
        }
        if(n==6||n==2||n==5||n==4||n==3||n==7){
            for(int i=1;i<=9;i++){
                if(u[i]==n){
                    cout<<i<<'\n';
                    break;
                }
            }
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<'\n';
        }else if(n%7==1){
            cout<<10;
            for(int i=1;i<=(n-8)/7;i++){
                cout<<8;
            }
            cout<<'\n';
        }else if(n%7==2){
            cout<<1;
            for(int i=1;i<=(n-2)/7;i++){
                cout<<8;
            }
            cout<<'\n';
        }else if(n%7==3){
            cout<<23;
            for(int i=1;i<=(n-10)/7;i++){
                cout<<8;
            }
            cout<<'\n';
        }else if(n%7==4){
            cout<<20;
            for(int i=1;i<=(n-11)/7;i++){
                cout<<8;
            }
            cout<<'\n';
        }else if(n%7==5){
            cout<<2;
            for(int i=1;i<=(n-5)/7;i++){
                cout<<8;
            }
            cout<<'\n';
        }else if(n%7==6){
            cout<<6;
            for(int i=1;i<=(n-6)/7;i++){
                cout<<8;
            }
            cout<<'\n';
        }
    }
    return 0;
}
