#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    map<string,int>mp;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    cout<<52-mp.size();
    return 0;
}