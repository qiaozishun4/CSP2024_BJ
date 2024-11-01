#include<bits/stdc++.h>
using namespace std;
//int a[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[15] = {0, 0, 1, 7, 4, 2, 0, 8};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n < 2){
            printf("-1\n");
            continue;
        }
        int len = (n + 6) / 7;
        bool a0 = 0;
        for(int i = len;i >= 1;i--){
            if(i == 1){
                if(a[n]) printf("%d", a[n]);
                else{
                    if(a0) printf("0");
                    else printf("6");
                }
                break;
            }
            if(((i - 1) * 7 >= n - 6) && a0){
                printf("0");
                n -= 6;
            }
            else if((i - 1) * 7 >= n - 2){
                printf("1");
                n -= 2;
                a0 = 1;
            }
            else if((i - 1) * 7 >= n - 5){
                printf("2");
                n -= 5;
                a0 = 1;
            }
            else if((i - 1) * 7 >= n - 4){
                printf("4");
                n -= 4;
                a0 = 1;
            }
            else if((i - 1) * 7 >= n - 6){
                printf("6");
                n -= 6;
                a0 = 1;
            }
            else{
                if(n != 8) printf("8"), n -= 7;
                else{
                    if(!a0) printf("6");
                    else printf("0");
                    n -= 6;
                }
                a0 = 1;
            }
        }
        printf("\n");
    }
    return 0;
}
