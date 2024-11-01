#include <bits/stdc++.h>
using namespace std;
string s[25]={"","-1","1","7","4","2","6","8","10","18","22","20","28","68","88"};
int nc[10]{6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;scanf("%d",&t);
    for(int _=1;_<=t;++_){
        int a;scanf("%d",&a);
        if(a<=14)cout << s[a] << endl;
        else{
            if(a%7==0){
                for(int i=1;i<=a/7;++i)printf("8");
            }
            else if(a%7==1){
                printf("10");
                for(int i=2;i<=a/7;++i)printf("8");
            }
            else if(a%7==2){
                printf("1");
                for(int i=1;i<=a/7;++i)printf("8");
            }
            else if(a%7==3){
                printf("200");
                for(int i=3;i<=a/7;++i)printf("8");
            }
            else if(a%7==4){
                printf("20");
                for(int i=2;i<=a/7;++i)printf("8");
            }
            else if(a%7==5){
                printf("2");
                for(int i=1;i<=a/7;++i)printf("8");
            }
            else if(a%7==6){
                printf("6");
                for(int i=1;i<=a/7;++i)printf("8");
            }
            putchar(10);
        }
    }
    return 0;
}