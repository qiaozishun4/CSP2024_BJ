#include<bits/stdc++.h>
using namespace std;
string s[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> s[i];
    int ans = 0;
    for(int i = 1;i <= n;i++){
        bool b = 0;
        for(int j = 1;j < i;j++){
            if(s[i] == s[j])b = 1;
        }
        if(!b)ans++;
    }
    cout << 52 - ans << endl;
    return 0;
}