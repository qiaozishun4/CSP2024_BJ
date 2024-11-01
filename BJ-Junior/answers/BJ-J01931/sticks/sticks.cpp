#include<bits/stdc++.h>
using namespace std;
void print8(int len){
    for(int i = 1;i <= len;i++){
        printf("8");
    }
}

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        if(n == 1) printf("-1\n");
        else if(n == 2) printf("1\n");
        else if(n == 3) printf("7\n");
        else if(n == 4) printf("4\n");
        else if(n == 5) printf("2\n");
        else if(n == 6) printf("6\n");
        else if(n % 7 == 0){
            int len = n / 7;
            print8(len);
            printf("\n");
        }
        else if(n % 7 == 1){
            int len = n / 7 + 1;
            printf("10");
            print8(len - 2);
            printf("\n");
        }
        else if(n % 7 == 2){
            int len = n / 7 + 1;
            printf("1");
            print8(len - 1);
            printf("\n");
        }
        else if(n % 7 == 3){
            int len = n / 7 + 1;
            if(len >= 3){
                printf("200");
                print8(len - 3);
            }
            else{
                printf("22");
            }
            printf("\n");
        }
        else if(n % 7 == 4){
            int len = n / 7 + 1;
            printf("20");
            print8(len - 2);
            printf("\n");
        }
        else if(n % 7 == 5){
            int len = n / 7 + 1;
            printf("2");
            print8(len - 1);
            printf("\n");
        }
        else if(n % 7 == 6){
            int len = n / 7 + 1;
            printf("6");
            print8(len - 1);
            printf("\n");
        }
    }
    return 0;
}
/*
cd ~/GJH/sticks && g++ sticks.cpp && ./a.out


*/