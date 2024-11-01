#include<iostream>
using namespace std;
bool myhash[4][15];
int n, ans;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int c, p;
        if(s[0] == 'D') c = 0;
        else if(s[0] == 'C') c = 1;
        else if(s[0] == 'H') c = 2;
        else c = 3;

        if(s[1] == 'A') p = 1;
        else if(s[1] == 'T') p = 10;
        else if(s[1] == 'J') p = 11;
        else if(s[1] == 'Q') p = 12;
        else if(s[1] == 'K') p = 13;
        else p = s[1] - '0';

        myhash[c][p] = true;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= 13; j++) {
            if(!myhash[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

