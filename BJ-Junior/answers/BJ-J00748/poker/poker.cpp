#include<iostream>
using namespace std;

int n, tmp, ans;
bool vis[5][20];
char a, b;

int to_number(char s){
    if (s == 'A'){
        return 1;
    } else if (s == 'T'){
        return 10;
    } else if (s == 'J'){
        return 11;
    } else if (s == 'Q'){
        return 12;
    } else if (s == 'K'){
        return 13;
    } else return (int)(s - '0');
}

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b;
        tmp = to_number(b);
        if (a == 'D'){
            vis[1][tmp] = 1;
        } else if (a == 'C'){
            vis[2][tmp] = 1;
        } else if (a == 'H'){
            vis[3][tmp] = 1;
        } else {
            vis[4][tmp] = 1;
        }
    }
    for (int i = 1; i <= 4; ++i){
        for (int j = 1; j <= 13; ++j){
            if (!vis[i][j]){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
