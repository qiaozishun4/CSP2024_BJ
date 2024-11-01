#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s[101];
int ans=52,n;
bool f(string a,int x){
    for(int i=1;i<x;i++){
        if(a==s[i]) return false;
    }
    return true;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(f(s[i],i)) ans--;
    }
    cout<<ans;
    return 0;
}