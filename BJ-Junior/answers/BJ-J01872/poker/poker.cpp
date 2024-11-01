#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n; cin >> n;
    int a[100] = {0};
    for(int i=1; i<=n; i++){
        string s; cin >> s;
        int x = 0;
        if(s[0] == 'D')
            x += 13;
        if(s[0] == 'H')
            x += 26;
        if(s[0] == 'S')
            x += 39;
        if('2' <= s[1] && s[1] <= '9')
            x += (s[1] - '0');
        else if(s[1] == 'A')
            x += 1;
        else{
            if(s[1] == 'T')
                x += 10;
            else if(s[1] == 'J')
                x += 11;
            else if(s[1] == 'Q')
                x += 12;
            else if(s[1] == 'K')
                x += 13;
        }
        a[x]++;
    }
    int ans = 0;
    for(int i=1; i<=52; i++){
        if(!a[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}