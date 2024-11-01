#include <bits/stdc++.h>
using namespace std;
int n,cnt;
bool a[4*52+1];
int d(char f){
    if (f == 'A') return 1;
    if (f == 'T') return 10;
    if (f == 'J') return 11;
    if (f == 'Q') return 12;
    if (f == 'K') return 13;
    return int(f)-48;
}
int h(char f){
    if (f == 'D') return 1;
    if (f == 'C') return 2;
    if (f == 'H') return 3;
    if (f == 'S') return 4;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;
    while(n--){
        char s[2];
        cin >> s;
        if (!a[4*d((s[1])-1)+h(s[0])]){
            a[4*d((s[1])-1)+h(s[0])] = true;
            cnt++;
        }
    }
    cout << 52 - cnt <<endl;
    return 0;
}
