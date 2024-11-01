#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n,ans=0,a[60]={0};
    cin>>n;
    //string s;
    //map<long long , string > mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //mp[s[i]]+=1;
    }
    cout<<52-n;/*
    for(int i=1;i<=n;i++){
        if(!mp[s[i]]){
            ans+=1;
        }
    }
    cou<<52-ans;*/
    return 0;
}
