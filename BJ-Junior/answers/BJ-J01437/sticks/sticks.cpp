#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;

void init(){
    mp[1]=-1;
    mp[2]=1;
    mp[3]=7;
    mp[4]=4;
    mp[5]=2;
    mp[6]=6;
    mp[7]=8;
}

void operate(int n){
    if(n<7){
        cout<<mp[n]<<endl;
        return;
    }
    mp[6]=0;
    if(n%7==0){
        for(int i=0;i<n/7;i++){
            cout<<8;
        }
        cout<<endl;
        return;
    }
    if(n%7<=2){
        cout<<1;
        n-=2;
    }
    else if(n%7<=5){
        cout<<2;
        n-=5;
    }
    else{
        cout<<6;
        n-=6;
    }
    while(n>7&&n%7!=0){
        cout<<0;
        n-=6;
    }
    if(n<=7){
        cout<<mp[n]<<endl;
        return;
    }
    for(int i=0;i<n/7;i++){
        cout<<8;
    }
    cout<<endl;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    init();
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        operate(n);
    }
    return 0;
}
