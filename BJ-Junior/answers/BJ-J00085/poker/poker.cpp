#include <bits/stdc++.h>
using namespace std;
map <string ,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string t;
    cin>>n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin>>t;
        if(!mp[t]){
            cnt++;
            mp[t] = 1;
        }
    }
    cout<<52-cnt;
}
