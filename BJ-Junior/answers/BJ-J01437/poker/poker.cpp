#include <bits/stdc++.h>

using namespace std;

map<string,bool> mp;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int T;
    cin>>T;
    int cnt=0;
    while(T--){
        string s;
        cin>>s;
        if(mp[s]!=true){
            cnt++;
            mp[s]=true;
        }
    }
    cout<<52-cnt<<endl;
    return 0;
}
