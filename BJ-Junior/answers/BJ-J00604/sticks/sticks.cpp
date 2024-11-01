#include <iostream>
using namespace std;
int count_number[10] = {6,2,5,5,4,5,6,3,7,6};
int ans_arry[60];
int dabiioa[15] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int shu(int x){
    int ans = 0;
    int fxf = x;
    while(fxf){
        ans += count_number[fxf%10];
        fxf /= 10;
    }
    return ans;
}
void repeat(char chx,int loop_number){
    int i = loop_number;
    if(i <= 0){
        return;
    }
    while(i--){
        printf("%c",chx);
    }
    return;
}
int main(){
 /*   for(int i = 1; i <= 100000000; i++){
        int tmp = shu(i);
        if(ans_arry[tmp] == 0){
            ans_arry[tmp] = i;
        }
    }

    for(int i = 1; i <= 100; i++){
        printf("%10d ",ans_arry[i]);
        if(i%7 == 0){
            printf("\n");
        }
    }*/
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n <= 10){
            printf("%d",dabiioa[n]);
        }else{
            if(n%7 == 0){
                repeat('8',n/7);
            }else if(n%7 == 1){
                printf("10");
                repeat('8',n/7-1);
            }else if(n%7 == 2){
                printf("1");
                repeat('8',n/7);
            }else if(n%7 == 3){
                printf("200");
                repeat('8',n/7-2);
            }else if(n%7 == 4){
                printf("20");
                repeat('8',n/7-1);
            }else if(n%7 == 5){
                printf("2");
                repeat('8',n/7);
            }else if(n%7 == 6){
                printf("6");
                repeat('8',n/7);
            }
        }
        printf("\n");
    }
    return 0;
}

