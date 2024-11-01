#include<bits/stdc++.h>
using namespace std;
int l[20]={6,2,5,5,4,5,6,3,7,6};
int l1[20]={-1,-1,1,7,4,2,6,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        if(n<=7)cout<<l1[n];
        else if(n%7==0){
            for(int i=1;i<=n/7;i++)printf("8");
        }
        else if(n%7==1){
            printf("10");
            for(int i=1;i<n/7;i++)printf("8");
        }
        else if(n%7==2){
            printf("1");
            for(int i=1;i<=n/7;i++)printf("8");
        }
        else if(n%7==3){
            if(n>16){
                printf("206");
                for(int i=1;i<n/7-1;i++)printf("8");
            }
            printf("22");
            for(int i=1;i<n/7;i++)printf("8");
        }
        else if(n%7==4){
            printf("20");
            for(int i=1;i<n/7;i++)printf("8");

        }
        else if(n%7==5){
            printf("2");
            for(int i=1;i<=n/7;i++)printf("8");
        }
        else if(n%7==6){
            printf("6");
            for(int i=1;i<=n/7;i++)printf("8");
        }
        cout<<endl;
    }
    return 0;
}
//0 1 2 3 4 5 6 7 8 9
//6 2 5 5 4 5 6 3 7 6
