#include <iostream>
using namespace std;
int f[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n = 0;
bool check(int t){
    int sum = 0;
    do{
        sum += f[t % 10];
        t /= 10;
    }
    while(t > 0);
    if(sum == n){
        return 1;
    } else {
        return 0;
    }
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        bool flag = 0;
        for(int i = 1; i <= 100000; i++){
            if(check(i) == 1){
                printf("%d\n", i);
                flag = 1;break;
            }
        }
        if(flag == 0){
            printf("-1\n");
        }
    }
    return 0;
}
