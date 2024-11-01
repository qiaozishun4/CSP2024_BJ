#include<bits/stdc++.h>
using namespace std;

string s[110];
long long n, cnt;
map<string, int>mp;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
    }
    for(int i = 1; i <= n; i++){
        if(mp[s[i]] == 0){
            mp[s[i]] = 1;
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}