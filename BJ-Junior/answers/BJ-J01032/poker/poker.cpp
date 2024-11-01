#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
bool a[50][50];
int ans = 0;

int trans(char t){
    if(t >='2' && t<='9') return int(t-'0');
    if(t=='A') return 1;
    if(t=='T') return 10;
    if(t=='J') return 11;
    if(t=='Q') return 12;
    if(t=='K') return 13;

    if(t=='D') return 1;
    if(t=='C') return 2;
    if(t=='H') return 3;
    if(t=='S') return 4;
}

int main(){

    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        char x, y;
        cin>>x>>y;
        int ii = trans(x), jj = trans(y);
        //cout<<jj<<' '<<ii<<endl;
        a[jj][ii] = true;
    }
    for(int i=1; i<=13; i++){
        for(int j=1; j<=4; j++){
            //cout<<a[i][j]<<' ';
            if(!a[i][j]) ans++;
        }//cout<<endl;
    }
    cout<<ans<<endl;

    return 0;
}
