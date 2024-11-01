#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
bool poker[20][10];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        string s;
        int x,y;
        cin>>s;
        if(s[0]=='D') y=1;else if(s[0]=='C') y=2;else if(s[0]=='H') y=3;else y=4;
        if(s[1]=='A') x=1;else if(s[1]=='T') x=10;else if(s[1]=='J') x=11;else if(s[1]=='Q') x=12;else if(s[1]=='K') x=13;else x=s[1]-'0';
        poker[x][y]=true;
    }
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(!poker[i][j]) ans++;
        }
    }
    cout<<ans;
    return 0;
}