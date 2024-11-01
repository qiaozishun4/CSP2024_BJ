#include<bits/stdc++.h>
using namespace std;
int a[21] = {0,-1,1,7,4,2,6,8,10,18,40,20,28,80,128,108,202,200,208,288,808};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,m;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        if(m % 7 == 0){
            string sum;
            int ans = m / 7;
            while(ans--){
                printf("8");
            }
            printf("\n");
        }else if(m % 7 == 1){
            string sum;
            int ans = m / 7 + 1;
            for(int i = 1; i <= ans; i++){
                if(i == 1) printf("1");
                else if(i == 2) printf("0");
                else printf("8");
            }
            printf("\n");
        }else if(m % 7 == 6 && m > 6){
            printf("80");
            int ans = m / 7 + 1;
            while(ans--) printf("8");
            printf("\n");
        }else{
            printf("%d\n",a[m]);
        }
    }
    return 0;
}