#include <bits/stdc++.h>
const int d[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int t;
bool check(int n, int i){
    if(i == 0){
        if (n == 0)     return true;
        return false;
    }
    int mod = d[i % 10];
    if(n < mod) return false;
    return check(n - mod, i / 10);
}

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
         //   printf("i:%d\n", i);
        int n;
        scanf("%d", &n);
        if(n < 2){
            printf("-1\n");
            continue;
        }
        int j = 1;
        while(!check(n, j)){
            ++j;
        }
        printf("%d\n", j);
    }
    return 0;
}
