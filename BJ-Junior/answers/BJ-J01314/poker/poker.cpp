#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,i,j,c0,c1,c2,f0=0,f1=0,f2=0;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    map<string,long long> m0;
    cin>>n;
    string s0;
    for(i=1;i<=n;i++){
        cin>>s0;
        m0[s0]++;
    }
    for(auto u0:m0){
        f0++;
    }
    cout<<52-f0;
    return 0;
}

