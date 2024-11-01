#include <bits/stdc++.h>
using namespace std;
int n;bool a[4][13];
int check(const char c){
    if(c == 'A' || c == 'D') return 0;
    if(c == '2' || c == 'C') return 1;
    if(c == '3' || c == 'H') return 2;
    if(c == '4' || c == 'S') return 3;
    if(c == 'T')    return 9;
    if(c == 'J')    return 10;
    if(c == 'Q')    return 11;
    if(c == 'K')    return 12;
    return c - '0' - 1;
}
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("\n");
        int num = check(getchar());
        int num1 = check(getchar());
        //printf("%d %d\n", num, num1);
        a[num][num1] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 13; ++j)
            if (!a[i][j])   ++cnt;
    }
    printf("%d", cnt);
    return 0;
}
