#include <stdio.h>
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n%7==0){
            for(int i=0;i<n/7;i++)putchar('8');
            puts("");
        }
        else if(n%7==1){
            putchar('1');
            putchar('0');
            for(int i=0;i<(n-8)/7;i++)putchar('8');
            puts("");
        }
    }
    return 0;
}
