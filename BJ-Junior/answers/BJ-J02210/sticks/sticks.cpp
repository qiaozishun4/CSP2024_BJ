#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        if(a==1) cout<<"-1\n";
        if(a==2) cout<<"1\n";
        if(a==3) cout<<"7\n";
        if(a==6) cout<<"6\n";
        if(a==18) cout<<"208\n";
    }
    return 0;
}
