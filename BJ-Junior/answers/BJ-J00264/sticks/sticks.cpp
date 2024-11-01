#include<bits/stdc++.h>
using namespace std;
int a[11]={1,7,4,2,6,8,10,24,22,20,60};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        int k=0;
        scanf("%d", &n);
        if(n<=1){printf("-1\n");continue;}
        if(n>12){
            int m=(n-12)/7;
            if(!(n-12)%7)k=m;
            else k=m+1;
            n-=k*7;
        }printf("%d",a[n-2]);
        while(k--)printf("8");
        printf("\n");
    }
}
