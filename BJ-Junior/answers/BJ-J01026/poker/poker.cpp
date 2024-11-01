#include<bits/stdc++.h>
using namespace std;
map<char, int> mp[5];
char ch[14] = {'0', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
char pl[5] = {'0', 'D', 'C', 'H', 'S'};
int n, ans;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int k = 0;
        for(int j = 1; j <= 4; j++){
            if(pl[j] == s[0])
                k = j;
        }
        mp[k][s[1]]++;
    }
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            if(mp[i][ch[j]] == 0)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
