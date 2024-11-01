#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
map<string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        if(!mp[s]) cnt++;
        mp[s]=true;
    }
    cout<<52-cnt;
    return 0;
}
