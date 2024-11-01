#include <iostream>
#include <string>
using namespace std;
int f[10][15] = {0};
int func(char t){
    if(t >= '0' && t <= '9'){
        return (int)(t - '0');
    } else {
        if(t == 'A'){
            return 1;
        } else if(t == 'T'){
            return 10;
        } else if(t == 'J'){
            return 11;
        } else if(t == 'Q'){
            return 12;
        } else if(t == 'K'){
            return 13;
        }
    }
}
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n = 0, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(s[0] == 'D'){
            f[1][func(s[1])] = 1;
        }
        if(s[0] == 'C'){
            f[2][func(s[1])] = 1;
        }
        if(s[0] == 'H'){
            f[3][func(s[1])] = 1;
        }
        if(s[0] == 'S'){
            f[4][func(s[1])] = 1;
        }
    }
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            if(f[i][j] == 0){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
