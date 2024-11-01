#include<iostream>
using namespace std;
int t,n;
int a[]={0,-1,1,7,4,2,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<7){
            printf("%d\n",a[n]);
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==1){
            printf("12");
            for(int i=1;i<n/7;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==2){
            printf("1");
            for(int i=1;i<=n/7;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==3){
            printf("22");
            for(int i=1;i<n/7;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==4){
            printf("20");
            for(int i=1;i<n/7;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==5){
            printf("2");
            for(int i=1;i<=n/7;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==6){
            printf("6");
            for(int i=1;i<=n/7;i++)printf("8");
            printf("\n");
            continue;
        }
    }
    return 0;
}
