#include<bits/stdc++.h>
using namespace std;
int n, x[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, t;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n <= 1){
            printf("-1\n"); continue;
        }
        int m = n % 7; n -= m;
        if(m == 1) {
            if(n >= 7) printf("10"), n -= 7;
        }if(m == 2) printf("1");
        if(m == 3){
            if(n >= 14) printf("200"), n -= 14;
            else if(n >= 7) printf("22"), n -= 7;
            else printf("7");
        }if(m == 4){
            if(n >= 7) printf("20"), n -= 7;
            else printf("4");
        }if(m == 5) printf("2");
        if(m == 6) printf("6");
        for(int i = 1; i <= n / 7; i++) printf("8");
        printf("\n");
    }
    return 0;
}