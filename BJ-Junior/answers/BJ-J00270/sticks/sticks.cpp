#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int n, a;
    scanf("%d", &n);
    for(int j = 1; j <= n; j++){
        scanf("%d", &a);
        if(a == 1){
            printf("-1\n");
        }
        if(a == 2){
            printf("1\n");
        }
        if(a == 3){
            printf("7\n");
        }
        if(a == 4){
            printf("4\n");
        }
        if(a == 5){
            printf("2\n");
        }
        if(a == 6){
            printf("6\n");
        }
        if(a == 7){
            printf("8\n");
        }
        if(a == 8){
            printf("10\n");
        }
        if(a == 9){
            printf("18\n");
        }
        if(a == 10){
            printf("22\n");
        }
        if(a == 11){
            printf("20\n");
        }
        if(a == 12){
            printf("28\n");
        }
        if(a == 13){
            printf("68\n");
        }
        if(a == 14){
            printf("88\n");
        }
        if(a > 14){
            if(a % 7 == 0){
                for(int i = 1; i <= n / 7 + 1; i++){
                    printf("8");
                }
                printf("\n");
            }
            else if(a % 7 == 1){
                printf("10");
                for(int i = 1; i <= (n - 8) / 7 +1;){
                    printf("8");
                    i++;
                }
                printf("\n");
            }
            else if(a % 7 == 2){
                printf("1");
                for(int i = 1; i <= (n - 2) / 7 + 1;){
                    printf("8");
                    i++;
                }
                printf("\n");
            }
            else if(a % 7 == 3){
                printf("22");
                for(int i = 1; i <= (n - 10) / 7 + 1;){
                    printf("8");
                    i++;
                }
                printf("\n");
            }
            else if(a % 7 == 4){
                printf("20");
                for(int i = 1; i <= (n - 11) / 7 + 1;){
                    printf("8");
                    i++;
                }
                printf("\n");
            }
            else if(a % 7 == 5){
                printf("2");
                for(int i = 1; i <= (n - 5) / 7 +1;){
                    printf("8");
                    i++;
                }
                printf("\n");
            }
            else if(a % 7 == 6){
                printf("6");
                for(int i = 1; i <= (n - 6) / 7 + 1;){
                    printf("8");
                    i++;
                }
                printf("\n");
            }
        }
    }
    return 0;
}