#include<bits/stdc++.h>
using namespace std;
int mp[]={-1,-1,1,7,4,2,0,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<7){
            if(n==6)cout<<6<<endl;
            else cout<<mp[n]<<endl;
        }else{
            n-=5;
            cout<<2;
            while(n>=8){
                n-=6;
                cout<<0;
            }
            cout<<mp[n]<<endl;
        }
    }
    return 0;
}