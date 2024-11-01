#include<bits/stdc++.h>
using namespace std;

string s="  174268";

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        if(n<2){
            printf("-1\n");
            continue;
        }
        if(n<=7){
            printf("%c\n",s[n]);
            continue;
        }
        if(n%7==1){
            printf("10");
            n-=7;
        }
        else if(n%7==2){
            printf("18");
            n-=7;
        }
        else if(n%7==3){
            printf("22");
            n-=7;
        }
        else if(n%7==4){
            printf("20");
            n-=7;
        }
        else printf("%c",s[n%7]);
        for(int i=0;i<n/7;i++)printf("8");
        printf("\n");
    }
    return 0;
}
