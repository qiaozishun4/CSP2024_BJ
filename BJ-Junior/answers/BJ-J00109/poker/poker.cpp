#include<bits/stdc++.h>
using namespace std;
map<string, int>mp;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, ans = 52;
    string s;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(!mp[s]) mp[s] = 1, ans--;
    }
    printf("%d", ans);
    return 0;
}
