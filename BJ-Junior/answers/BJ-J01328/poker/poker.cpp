#include<bits/stdc++.h>
using namespace std;
bool vis[10][100];
int tointnum(char c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }
    if(c=='A') return 1;
    if(c=='T') return 10;
    if(c=='J') return 11;
    if(c=='Q') return 12;
    if(c=='K') return 13;
}
int tointfir(char c){
    if(c=='D') return 1;
    if(c=='C') return 2;
    if(c=='H') return 3;
    if(c=='S') return 4;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        int a,b;
        a=tointfir(s[0]);
        b=tointnum(s[1]);
        vis[a][b]=true;
    }
    int cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(vis[i][j]){
                cnt++;
            }
        }
    }
    cout<<52-cnt;
    return 0;
}
