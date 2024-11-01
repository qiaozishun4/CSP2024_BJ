#include <bits/stdc++.h>
using namespace std;

const int CNT[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int t;

int len(int x){
    int cnt = 0;
    while (x != 0){
        cnt ++;
        x /= 10;
    }
    return cnt;
}
int sum(int x){
    int sum = 0;
    while (x != 0){
        sum += CNT[x % 10];
        x /= 10;
    }
    return sum;
}

int main(){
    scanf("%d", &t);
    int ans = -1;
    while (t--){
        int n;
        scanf("%d", &n);
        for (int i = 1; len(i) <= n / 2; i++){
            if (sum(i) == n){
                ans = i;
                break ;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
