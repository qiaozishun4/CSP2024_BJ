#include<bits/stdc++.h>
using namespace std;
int dk[]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,f=0;
        int ans=0;
        scanf("%d",&n);
        if(n==6){printf("6\n");continue;}
        if(n==2){printf("1\n");continue;}
        if(n==5){printf("2\n");continue;}
        if(n==7){printf("8\n");continue;}
        if(n==3){printf("7\n");continue;}
        if(n==4){printf("4\n");continue;}
        if(n==1){printf("-1\n");continue;}
        if(n%7==0){
            for(int i=1;i<=n/7;i++)printf("8");
            printf("\n");
            f=1;
            continue;
        }
        ans=n/7-1;
        n=n-ans*7;
        if(n==8){
            printf("10");
            for(int i=1;i<=ans;i++)printf("8");
            printf("\n");
        }
        if(n==9){
            printf("18");
            for(int i=1;i<=ans;i++)printf("8");
            printf("\n");
        }
        if(n==10){
            printf("22");
            for(int i=1;i<=ans;i++)printf("8");
            printf("\n");
        }
        if(n==11){
            printf("20");
            for(int i=1;i<=ans;i++)printf("8");
            printf("\n");
        }
        if(n==12){
            printf("28");
            for(int i=1;i<=ans;i++)printf("8");
            printf("\n");
        }
        if(n==13){
            printf("68");
            for(int i=1;i<=ans;i++)printf("8");
            printf("\n");
        }
    }
    return 0;
}
