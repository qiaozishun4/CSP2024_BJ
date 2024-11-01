#include<bits/stdc++.h>
using namespace std;
int n;
string s[55];
int a[5][14];
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        if(s[i][1]=='A') {
            s[i][1]='1';
        }
        if(s[i][1]=='T') {
            s[i][1]='9'+1;
        }
        if(s[i][1]=='J') {
            s[i][1]='9'+2;
        }
        if(s[i][1]=='Q') {
            s[i][1]='9'+3;
        }
        if(s[i][1]=='K') {
            s[i][1]='9'+4;
        }
    }
    for(int i=1;i<=n;i++) {
        int c=int(s[i][1]-'0');
        if(s[i][0]=='D') {
            a[1][c]++;
        }
        if(s[i][0]=='C') {
            a[2][c]++;
        }
        if(s[i][0]=='H') {
            a[3][c]++;
        }
        if(s[i][0]=='S') {
            a[4][c]++;
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++) {
        for(int j=1;j<=13;j++) {
            if(a[i][j]==0) {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}