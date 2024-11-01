#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        if (n%7==0){
            for (int i=1;i<=n/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        int b=0;
        while (n-7>=7){
            b++;
            n-=7;
        }
        if (n==1){
            printf("-1\n");
        }
        else if (n==2){
            printf("1\n");
        }
        else if (n==3){
            printf("7\n");
        }
        else if (n==4){
            printf("4\n");
        }
        else if (n==5){
            printf("2\n");
        }
        else if (n==6){
            printf("6\n");
        }
        else if (n==7){
            printf("8");
            printf("\n");
        }
        else if (n==8){
            printf("10");
            for (int i=1;i<=b;i++){
                printf("8");
            }
            printf("\n");
        }
        else if (n==9){
            printf("18");
            for (int i=1;i<=b;i++){
                printf("8");
            }
            printf("\n");
        }
        else if (n==10){
            printf("22");
            for (int i=1;i<=b;i++){
                printf("8");
            }
            printf("\n");
        }
        else if (n==11){
            printf("20");
            for (int i=1;i<=b;i++){
                printf("8");
            }
            printf("\n");
        }
        else if (n==12){
            printf("28");
            for (int i=1;i<=b;i++){
                printf("8");
            }
            printf("\n");
        }
        else{
            printf("68");
            for (int i=1;i<=b;i++){
                printf("8");
            }
            printf("\n");
        }
    }
    return 0;
}
/*
                    /////////////////////////////////////         PPPPPPPPPPPPPPPPPPPPPPPPPPPPPP                  888888888888888888888888
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8   
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           P                             P                8                        8
                                    ///                           PPPPPPPPPPPPPPPPPPPPPPPPPPPPPP                   88888888888888888888888 
                                    ///                           P                                               8                       8 
                                    ///                           P                                              8                         8
                                    ///                           P                                             8                           8 
                                    ///                           P                                             8                           8 
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                                    ///                           P                                             8                           8
                           ///     ///                            P                                             8                           8
                            /////////                             P                                              888888888888888888888888888
*/