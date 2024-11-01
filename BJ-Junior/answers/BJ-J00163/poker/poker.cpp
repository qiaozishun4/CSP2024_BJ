#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int n,cnt;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> s;
        mp[s]++;
    }
    for(auto kv:mp){
        ++cnt;
        //cout << kv.first << endl;
    }
    cout << 52-cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
