#include<bits/stdc++.h>
#define rt return
using namespace std;
typedef long long ll;
ll n,t[5][15],cnt;
string s;
ll ch1(char x){
    if (x=='D') rt 1;
    if (x=='C') rt 2;
    if (x=='H') rt 3;
    if (x=='S') rt 4;
}
ll ch2(char x){
    if (x>='2' && x<='9') rt x-'0';
    if (x=='A') rt 1;
    if (x=='T') rt 10;
    if (x=='J') rt 11;
    if (x=='Q') rt 12;
    if (x=='K') rt 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>s;
        t[ch1(s[0])][ch2(s[1])]++;
    }
    for (ll i=1;i<=4;i++) for (ll j=1;j<=13;j++) if (t[i][j]>0) cnt++;
    cout<<52-cnt;
    return 0;
}
