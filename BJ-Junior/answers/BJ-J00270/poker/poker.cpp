#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    int cnt = 0;
    int a[5][14] = {0};
    char c[2];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int d1 = 0, d2 = 0;
        scanf("%c %c", &c[0], &c[1]);
        if(c[0] == 'D'){
            d1 = 1;
        }
        if(c[0] == 'C'){
            d1 = 2;
        }
        if(c[0] == 'H'){
            d1 = 3;
        }
        if(c[0] == 'S'){
            d1 = 4;
        }
        if(c[1] == 'A'){
            d2 = 1;
        }
        else if(c[1] == 'T'){
            d2 = 10;
        }
        else if(c[1] == 'J'){
            d2 = 11;
        }
        else if(c[1] == 'Q'){
            d2 = 12;
        }
        else if(c[1] == 'K'){
            d2 = 13;
        }
        else{
            d2 = c[1] - '0';
        }
        a[d1][d2] = 1;
    }
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            if(a[i][j] == 0){
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}