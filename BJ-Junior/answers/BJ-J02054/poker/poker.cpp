#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    map<string,int> mp;
    int n,s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        if(!mp.count(a)){
            mp[a]=1;
            s++;
        }
    }
    cout<<52-s;
    return 0;
}