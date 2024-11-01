#include<bits/stdc++.h>
using namespace std;
int n, ans;
char s, t;
bool flag[5][14];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf(" %c%c", &s, &t);
        int X1, X2;
        if(s == 'D')
            X1 = 1;
        if(s == 'C')
            X1 = 2;
        if(s == 'H')
            X1 = 3;
        if(s == 'S')
            X1 = 4;
        if(t == 'A')
            X2 = 1;
        if((t - '0') > 1 && (t - '0') < 10)
            X2 = t - '0';
        if(t == 'T')
            X2 = 10;
        if(t == 'J')
            X2 = 11;
        if(t == 'Q')
            X2 = 12;
        if(t == 'K')
            X2 = 13;
        flag[X1][X2] = true;
    }
    for(int i = 1; i <= 4; ++i)
        for(int j = 1; j <= 13; ++j)
            if(!flag[i][j])
                ++ans;
    printf("%d", ans);
    return 0;
}
