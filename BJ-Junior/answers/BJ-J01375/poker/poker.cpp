#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#define ll long long
using namespace std;
map<string,int>  m;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    string st;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>st;
        m[st]++;
    }
    for(auto i:m)ans++;
    if(ans>=52){
        cout<<0<<endl;
    }
    else{
        cout<<52-ans<<endl;
    }
    return 0;
}