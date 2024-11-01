#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int n,cnt; string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    while(n--){
        cin >> s;
        if(!mp[s]) cnt++,mp[s]=1;
    }cout << 52-cnt;
    return 0;
}
