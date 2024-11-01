#include <bits/stdc++.h>
using namespace std;
int cards[53],n;
char buf[2],a,b;
int tr(char);
int main(void){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%s",buf);
        a=buf[0];
        b=buf[1];
        if(isdigit(b)){
            cards[tr(a)+(b-'0')] = 1;
        }
        else if(b=='A') cards[tr(a)+1] = 1;
        else if(b=='T') cards[tr(a)+10] = 1;
        else if(b=='J') cards[tr(a)+11] = 1;
        else if(b=='Q') cards[tr(a)+12] = 1;
        else if(b=='K') cards[tr(a)+13] = 1;
    }
    int ans=52-accumulate(cards,cards+53,0);
    if(ans<0) cout << 0;
    else cout << ans;
    putchar('\n');
    return 0;
}
int tr(char c){
    if(c=='D') return 0;
    if(c=='C') return 13;
    if(c=='H') return 26;
    if(c=='S') return 39;
}
