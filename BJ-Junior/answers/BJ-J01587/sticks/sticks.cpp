#include<bits/stdc++.h>
using namespace std;
int ans[7]={0,10,1,200,20,2,6},p[7]={-1,-1,1,7,4,2,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n;cin>>n;
        if(n<7){
            cout<<p[n]<<endl;
            continue;
        }
        if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1||n%7==3||n%7==4){
            cout<<ans[n%7];
            for(int j=1;j<=n/7-1-(n%7==3);j++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            cout<<ans[n%7];
            for(int j=1;j<=n/7;j++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}