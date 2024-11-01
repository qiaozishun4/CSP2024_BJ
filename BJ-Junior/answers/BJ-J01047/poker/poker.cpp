#include<bits/stdc++.h>
using namespace std;
map<string,bool> mp;
int n,ans = 52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        string s;
        cin >> s;
        if(!mp[s]){
            ans--;
            mp[s] = true;
        }
    }
    cout << ans;
    return 0;
}