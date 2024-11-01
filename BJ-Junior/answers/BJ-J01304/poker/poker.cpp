#include <bits/stdc++.h>
using namespace std;
int d[15], c[15], h[15], s[15];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        char c1, c2;
        cin >> c1 >> c2;
        if(c1 == 'D'){
            if(c2 >= '2' && c2 <= '9') d[c2 - '0']++;
            if(c2 == 'A') d[1]++;
            if(c2 == 'T') d[10]++;
            if(c2 == 'J') d[11]++;
            if(c2 == 'Q') d[12]++;
            if(c2 == 'K') d[13]++;
        }
        if(c1 == 'C'){
            if(c2 >= '2' && c2 <= '9') c[c2 - '0']++;
            if(c2 == 'A') c[1]++;
            if(c2 == 'T') c[10]++;
            if(c2 == 'J') c[11]++;
            if(c2 == 'Q') c[12]++;
            if(c2 == 'K') c[13]++;
        }
        if(c1 == 'H'){
            if(c2 >= '2' && c2 <= '9') h[c2 - '0']++;
            if(c2 == 'A') h[1]++;
            if(c2 == 'T') h[10]++;
            if(c2 == 'J') h[11]++;
            if(c2 == 'Q') h[12]++;
            if(c2 == 'K') h[13]++;
        }
        if(c1 == 'S'){
            if(c2 >= '2' && c2 <= '9') s[c2 - '0']++;
            if(c2 == 'A') s[1]++;
            if(c2 == 'T') s[10]++;
            if(c2 == 'J') s[11]++;
            if(c2 == 'Q') s[12]++;
            if(c2 == 'K') s[13]++;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= 13; i++){
        if(!d[i]) cnt++;
        if(!c[i]) cnt++;
        if(!h[i]) cnt++;
        if(!s[i]) cnt++;
    }
    cout << cnt;
    return 0;
}
