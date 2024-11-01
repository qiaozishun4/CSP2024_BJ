#include<bits/stdc++.h>
using namespace std;
int hs[105], cnt;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        string sx;
        cin >> sx;
        int h, l;
        if(sx[0]=='D') h = 0;
        else if(sx[0]=='C') h = 1;
        else if(sx[0]=='H') h = 2;
        else if(sx[0]=='S') h = 3;
        if(sx[1]=='T') l = 10;
        else if(sx[1]=='J') l = 11;
        else if(sx[1]=='Q') l = 12;
        else if(sx[1]=='K') l = 13;
        else if(sx[1]=='A') l = 1;
        else l = sx[1]-48;
        hs[h*13+l] = 1;
    }
    for(int i = 1;i <= 52;i++){
        if(hs[i]==1)
            cnt++;
    }
    cout << 52-cnt;
    return 0;
}
