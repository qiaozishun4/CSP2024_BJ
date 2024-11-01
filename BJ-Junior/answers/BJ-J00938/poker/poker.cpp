#include<bits/stdc++.h>
using namespace std;
string s[60];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, cnt = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cnt = 0;
        cin >> s[i];
        for (int j = 1; j <= i - 1; j++)
            if(s[i] == s[j]) cnt++;
        if(cnt == 0)
            ans++;
    }
    cout << 52 - ans;
    return 0;
}
