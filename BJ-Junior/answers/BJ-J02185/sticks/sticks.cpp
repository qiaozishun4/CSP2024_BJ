#include<bits/stdc++.h>
using namespace std;
int a[55],ans[55];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    int k[10] = {0,-1,1,7,4,2,6,8};
    for(int i=1;i<=t;i++){
        if(a[i]>0&&a[i]<8){
            cout<<k[a[i]]<<endl;
            continue;
        }
        if(a[i]%7==0){
            for(int j=1;j<=(a[i]/7);j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(a[i]%7==1){
            cout<<10;
            for(int j=1;j<=(a[i]/7)-1;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}
