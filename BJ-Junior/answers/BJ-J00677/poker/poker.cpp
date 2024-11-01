#include <bits/stdc++.h>
using namespace std;

bool p[14][4];

inline int h(char c){
    if (c == 'D')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'H')
        return 2;
    return 3;
}


int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        if (s[1] == 'J')
            p[11][h(s[0])] = true;
        else if (s[1] == 'Q')
            p[12][h(s[0])] = true;
        else if (s[1] == 'K')
            p[13][h(s[0])] = true;
        else if (s[1] == 'A')
            p[1][h(s[0])] = true;
        else if (s[1] == 'T')
            p[10][h(s[0])] = true;
        else
            p[s[1] - '0'][h(s[0])] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= 13; i++)
        cnt += !p[i][0] + !p[i][1] + !p[i][2] + !p[i][3];
    cout << cnt;
    return 0;
}
