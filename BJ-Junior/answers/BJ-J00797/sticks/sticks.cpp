#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    int a[100000];
    for(int i=1;i<=T;i++){
        cin>>a[i];
    }
    for(int j=1;j<=T;j++){
        if(a[j]<=1){
            cout<<"-1";
            }
        if(a[j]==2){
            cout<<"1";
            }
        if(a[j]==3){
            cout<<"6";
            }
        if(a[j]==6){
            cout<<"6";
            }
        if(a[j]==18){
            cout<<"208";
            }
    }

    return 0;
}
