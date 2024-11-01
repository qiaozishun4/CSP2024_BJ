#include <bits/stdc++.h>
using namespace std;

const int N = 60;

int n;
char a, b;
int na, nb;
bool f[N];
int ans;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    cin.get();
    for(int i=1; i<=n; i++){
        scanf("%c%c", &a, &b);
        cin.get();
        if(a=='D') na = 0;
        if(a=='C') na = 1;
        if(a=='H') na = 2;
        if(a=='S') na = 3;
        if(b=='A') nb = 1;
        if(b>='2' && b<='9') nb = b - '0';
        if(b=='T') nb = 10;
        if(b=='J') nb = 11;
        if(b=='Q') nb = 12;
        if(b=='K') nb = 13;
        f[na*13+nb] = true;
    }
    for(int i=1; i<=52; i++){
        if(f[i]) ans++;
    }
    printf("%d", 52-ans);

    return 0;
}
