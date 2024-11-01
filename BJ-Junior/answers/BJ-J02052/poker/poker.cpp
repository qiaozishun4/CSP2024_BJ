#include<bits/stdc++.h>
using namespace std;
int n,ans;
int cnt[10][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        char c,op;
        string s;
        int x,y;
        cin >> s;
        op = s[0],c = s[1];
        if('0'<=c && c<='9'){
            x = c-'0';
        }
        else if(c=='T'){
            x = 10;
        }
        else if(c=='J'){
            x = 11;
        }
        else if(c=='Q'){
            x = 12;
        }
        else if(c=='K'){
            x = 13;
        }
        else if(c=='A'){
            x = 1;
        }
        if(op=='D'){
            y = 1;
        }
        else if(op=='C'){
            y = 2;
        }
        else if(op=='H'){
            y = 3;
        }
        else if(op=='S'){
            y = 4;
        }
        cnt[y][x]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!cnt[i][j]){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
