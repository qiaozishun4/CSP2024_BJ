#include<bits/stdc++.h>
using namespace std;
//D=方片 C=梅花 H=红桃 S=黑桃
int a[4][16];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        int color,num;
        if(s[0]=='D') color=0;
        if(s[0]=='C') color=1;
        if(s[0]=='H') color=2;
        if(s[0]=='S') color=3;
        if(s[1]=='A') num=1;
        if(s[1]=='2') num=2;
        if(s[1]=='3') num=3;
        if(s[1]=='4') num=4;
        if(s[1]=='5') num=5;
        if(s[1]=='6') num=6;
        if(s[1]=='7') num=7;
        if(s[1]=='8') num=8;
        if(s[1]=='9') num=9;
        if(s[1]=='T') num=10;
        if(s[1]=='J') num=11;
        if(s[1]=='Q') num=12;
        if(s[1]=='K') num=13;
        a[color][num]++;
    }
    int ans=0;
    for(int i=0;i<=3;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
