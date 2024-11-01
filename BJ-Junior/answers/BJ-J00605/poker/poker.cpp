#include<bits/stdc++.h>
using namespace std;
int n;
struct POKER {
    char fl, po;
    int num;
};
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    POKER poker[n];
    for(int i = 0; i < n; i ++)
        cin >> poker[i].fl >> poker[i].po;
    bool flag[52];
    memset(flag, false, sizeof(flag));
    for(int i = 0; i < n; i ++) {
        int c, d;
        if(poker[i].fl == 'D') c = 0;
        else if(poker[i].fl == 'C') c = 1;
        else if(poker[i].fl == 'H') c = 2;
        else c = 3;
        if(poker[i].po >= '2' && poker[i].po <= '9') d = poker[i].po - '0' - 1;
        else if(poker[i].po == 'A') d = 0;
        else if(poker[i].po == 'T') d = 9;
        else if(poker[i].po == 'J') d = 10;
        else if(poker[i].po == 'Q') d = 11;
        else d = 12;
        poker[i].num = c * 13 + d;
        flag[poker[i].num] = true;
    }
    int ans = 0;
    for(int i = 0; i < 52; i ++)
        if(flag[i] == false)
            ans++;
    cout << ans << endl;
    return 0;
}