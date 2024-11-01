#include<bits/stdc++.h>
using namespace std;
int cnt[5][20];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >>n;
    memset(cnt, 0, sizeof(cnt));
    while(n--){
        string s;
        cin >> s;
        int x, y;
        if(s[0] == 'D'){
            x = 1;
        }
        if(s[0] == 'C'){
            x = 2;
        }
        if(s[0] == 'H'){
            x = 3;
        }
        if(s[0] == 'S'){
            x = 4;
        }
        if(s[1] == 'A'){
            y = 1;
        }
        if(s[1] >= '2' && s[1] <= '9'){
            y = s[1] - '0';
        }
        if(s[1] == 'T'){
            y = 10;
        }
        if(s[1] == 'J'){
            y = 11;
        }
        if(s[1] == 'Q'){
            y = 12;
        }
        if(s[1] == 'K'){
            y = 13;
        }
        cnt[x][y] = 1;
    }
    int sum = 0;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            if(cnt[i][j] == 0){
                sum++;
            }
        }
    }
    cout <<sum;
    return 0;
}
