#include <bits/stdc++.h>
using namespace std;
bool p[10][100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
            string s;
        cin>>s;
        char a=s[0],b=s[1];
            int c;
            if(b=='A')c=1;
            else if(b=='T')c=10;
            else if(b=='J')c=11;
            else if(b=='Q')c=12;
            else if(b=='K')c=13;
            else c=b-'0';
        if(a=='D')p[1][c]=1;
        if(a=='C')p[2][c]=1;
        if(a=='H')p[3][c]=1;
        if(a=='S')p[4][c]=1;
    }
    int ct=0;
    for(int i=1;i<=4;++i){
        for(int j=1;j<=13;++j){
            if(p[i][j])++ct;
        }
    }
    cout<<52-ct;
    return 0;
}
