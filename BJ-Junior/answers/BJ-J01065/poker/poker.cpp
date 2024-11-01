#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<string,bool>mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]=true;
    }
    cout<<52-mp.size()<<endl;
    return 0;
}