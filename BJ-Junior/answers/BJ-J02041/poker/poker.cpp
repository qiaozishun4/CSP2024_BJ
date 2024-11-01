#include <bits/stdc++.h>
using namespace std;
int n,ans,a,b;
int pok[10][20];
char cnt,cnt1;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> cnt;
        if(cnt == 'D') a = 1;
        if(cnt == 'C') a = 2;
        if(cnt == 'H') a = 3;
        if(cnt == 'S') a = 4;
        cin >> cnt1;
        if(cnt1 == 'A') b = 1;
        if(cnt1 == '2') b = 2;
        if(cnt1 == '3') b = 3;
        if(cnt1 == '4') b = 4;
        if(cnt1 == '5') b = 5;
        if(cnt1 == '6') b = 6;
        if(cnt1 == '7') b = 7;
        if(cnt1== '8') b = 8;
        if(cnt1== '9') b = 9;
        if(cnt1 == 'T') b = 10;
        if(cnt1 == 'J') b = 11;
        if(cnt1 == 'Q') b = 12;
        if(cnt1 == 'K') b = 13;
        if(pok[a][b] == 1){
            continue;
        }
        pok[a][b]++;
        ans++;
    }
    cout << 52 - ans;
    return 0;
}
