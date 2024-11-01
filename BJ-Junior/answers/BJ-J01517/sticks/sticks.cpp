#include<bits/stdc++.h>
using namespace std;
int mp[10] = {6,2,5,5,4,5,6,3,7,6};
//2->1 , 3->7 , 4->4 , 5->2 , 6->0/6 , 7->8
int mp1[8] = {0,0,1,7,4,2,6,8};
int n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n == 1){
            printf("-1\n");
            continue;
        }
        if(n <= 7){
            printf("%d\n",mp1[n]);
            continue;
        }
        if(n%7 == 0){
            for(int i=1;i<=(n/7);i++) printf("8");
            printf("\n");
            continue;
        }
        if(n%7 == 1){
            printf("10");
            n -= 8;
            for(int i=1;i<=(n/7);i++) printf("8");
            printf("\n");
            continue;
        }
        if(n%7 == 2){
            printf("18");
            n -= 9;
            for(int i=1;i<=(n/7);i++) printf("8");
            printf("\n");
            continue;
        }
        if(n%7 == 3){
            printf("22");
            n -= 10;
            for(int i=1;i<=(n/7);i++) printf("8");
            printf("\n");
            continue;
        }
        if(n%7 == 4){
            printf("20");
            n -= 11;
            for(int i=1;i<=(n/7);i++) printf("8");
            printf("\n");
            continue;
        }
        if(n%7 == 5){
            printf("28");
            n -= 12;
            for(int i=1;i<=(n/7);i++) printf("8");
            printf("\n");
            continue;
        }
        if(n%7 == 6){
            printf("68");
            n -= 13;
            for(int i=1;i<=(n/7);i++) printf("8");
            printf("\n");
            continue;
        }
    }
    return 0;
}
