#include<bits/stdc++.h>
using namespace std;
int t,n,k;
inline void sol0(){
    for(int i=1;i<=k;i++)printf("8");
}

inline void sol1(){
    if(n==1){
        printf("-1");
    }else{
        printf("10");
        for(int i=1;i<=(k-1);i++)printf("8");
    }
}

inline void sol2(){
    if(n==2){
        printf("1");
    }else{
        printf("18");
        for(int i=1;i<=(k-1);i++)printf("8");
    }
}

inline void sol3(){
    if(n==3){
        printf("7");
    }else{
        printf("22");
        for(int i=1;i<=(k-1);i++)printf("8");
    }
}

inline void sol4(){
    if(n==4){
        printf("4");
    }else{
        printf("20");
        for(int i=1;i<=(k-1);i++)printf("8");
    }
}

inline void sol5(){
    if(n==5){
        printf("2");
    }else{
        printf("28");
        for(int i=1;i<=(k-1);i++)printf("8");
    }
}

inline void sol6(){
    if(n==6){
        printf("6");
    }else{
        printf("68");
        for(int i=1;i<=(k-1);i++)printf("8");
    }
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        k=n/7;
        if(n%7==0)sol0();
        else if(n%7==1)sol1();
        else if(n%7==2)sol2();
        else if(n%7==3)sol3();
        else if(n%7==4)sol4();
        else if(n%7==5)sol5();
        else if(n%7==6)sol6();
        printf("\n");
    }
    return 0;
}
