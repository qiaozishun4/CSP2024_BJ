#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n == 1)printf("-1");
        else if(n == 2)printf("1");
        else if(n == 3)printf("7");
        else if(n == 4)printf("4");
        else if(n == 5)printf("2");
        else if(n == 6)printf("6");
        else if(n % 7 == 0){
            for(int i = 1;i <= n / 7;i++)printf("8");
        }
        else if(n % 7 == 1){
            printf("10");
            for(int i = 1;i <= (n / 7) - 1;i++)printf("8");
        }
        else if(n % 7 == 2){
            printf("1");
            for(int i = 1;i <= n / 7;i++)printf("8");
        }
        else if(n % 7 == 3){
            printf("22");
            for(int i = 1;i <= (n / 7) - 1;i++)printf("8");
        }
        else if(n % 7 == 4){
            printf("20");
            for(int i = 1;i <= (n / 7) - 1;i++)printf("8");
        }
        else if(n % 7 == 5){
            printf("2");
            for(int i = 1;i <= n / 7;i++)printf("8");
        }
        else if(n % 7 == 6){
            printf("6");
            for(int i = 1;i <= n / 7;i++)printf("8");
        }
        printf("\n");
    }
    return 0;
}
