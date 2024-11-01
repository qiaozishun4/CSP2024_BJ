#include<bits/stdc++.h>
using namespace std;
int n, sum, f[300][300];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        char c1, c2;
        scanf(" %c%c", &c1, &c2);
        if(f[c1][c2] == 0) sum++;
        f[c1][c2] = 1;
    }printf("%d", 52 - sum);
    return 0;
}
