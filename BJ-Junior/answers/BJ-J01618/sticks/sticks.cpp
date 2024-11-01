#include<iostream>
#include<cstdio>
using namespace std;
int f[10]={6,2,5,5,4,5,6,3,7,6};
int ans[55]={-1,-1,1,7,4,3,6,8,10,18,22,20,28,68,88,108,188,200,208,288,988,888,1988,1888};
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=23) cout<<ans[n]<<endl;
        else if(n%7==0){
            int t=n/7;
            while(t--) cout<<8;
            cout<<endl;
        }else if(n%7==1){
            int t=n/7-1;
            cout<<10<<endl;
            while(t--) cout<<8;
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}