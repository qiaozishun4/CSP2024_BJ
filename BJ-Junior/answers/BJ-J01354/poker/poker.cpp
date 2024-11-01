#include<bits/stdc++.h>
using namespace std;
int n,ans;
map<string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    ans = 52;
    for(int i = 1;i <= n;i++){
        string s;
        cin >> s;
        if(!mp.count(s)){
            mp[s] = 1;
            ans--;
        }
    }
    cout << ans;
    return 0;
}
