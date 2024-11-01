#include <bits/stdc++.h>
using namespace std;
const int N=100;
int cnt[5][N];
int ki(char c){
    if (c=='D') return 1;
    if (c=='C') return 2;
    if (c=='H') return 3;
    return 4;
}
int nu(char c){
    if ('2'<=c && c<='9') return c-'0';
    if (c=='A') return 1;
    if (c=='T') return 10;
    if (c=='J') return 11;
    if (c=='Q') return 12;
    return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        cnt[ki(s[0])][nu(s[1])]++;
    }
    int ans=0;
    for (int i=1;i<=4;i++){
        for (int j=1;j<=13;j++){
            if (cnt[i][j]==0) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
