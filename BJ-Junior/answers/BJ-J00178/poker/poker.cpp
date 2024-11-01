#include<bits/stdc++.h>
using namespace std;
map<string,bool> m;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin >> n;
    string s[53];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(m[s[i]]==false){
            ans--;
            m[s[i]] = true;
        }
    }
    cout << ans;
    return 0;
}
