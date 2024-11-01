#include<iostream>
using namespace std;
int tmp[]={0,-1,1,7,4,2,6,8};
void solve(){
    int n;
    cin>>n;
    if(n<=7){
        cout<<tmp[n]<<'\n';
        return;
    }
    int m=n%7;
    if(m==0){
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
    }else if(m==1){
        cout<<"10";
        for(int i=1;i<n/7;i++){
            cout<<8;
        }
    }else if(m==2){
        cout<<1;
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
    }else if(m==3){
        if(n==10){
            cout<<22;
        }else{
            cout<<200;
            for(int i=1;i<n/7-1;i++){
                cout<<8;
            }
        }

    }else if(m==4){
        cout<<20;
        for(int i=1;i<n/7;i++){
            cout<<8;
        }
    }else if(m==5){
        cout<<2;
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
    }else if(m==6){
        cout<<6;
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
    }
    cout<<'\n';
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}
