#include <bits/stdc++.h>
using namespace std;

int t[5][15];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        char a, b;
        cin >> a >> b;
        if(a=='D'){
            if(b=='K')t[1][13]++;
            else if(b=='Q')t[1][12]++;
            else if(b=='J')t[1][11]++;
            else if(b=='T')t[1][10]++;
            else if(b=='A')t[1][1]++;
            else{
                t[1][b-'0']++;
            }
        }
        if(a=='C'){
            if(b=='K')t[2][13]++;
            else if(b=='Q')t[2][12]++;
            else if(b=='J')t[2][11]++;
            else if(b=='T')t[2][10]++;
            else if(b=='A')t[2][1]++;
            else{
                t[2][b-'0']++;
            }
        }
        if(a=='H'){
            if(b=='K')t[3][13]++;
            else if(b=='Q')t[3][12]++;
            else if(b=='J')t[3][11]++;
            else if(b=='T')t[3][10]++;
            else if(b=='A')t[3][1]++;
            else{
                t[3][b-'0']++;
            }
        }
        if(a=='S'){
            if(b=='K')t[4][13]++;
            else if(b=='Q')t[4][12]++;
            else if(b=='J')t[4][11]++;
            else if(b=='T')t[4][10]++;
            else if(b=='A')t[4][1]++;
            else{
                t[4][b-'0']++;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= 13;j++){
            if(!t[i][j]){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
