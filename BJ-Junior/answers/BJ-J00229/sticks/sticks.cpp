#include<stdio.h>
#include<cmath>
using namespace std;
int n;
int use[10]={
    6,//0
    2,//1
    5,//2
    5,//3
    4,//4
    5,//5
    6,//6
    3,//7
    7,//8
    6,//9
};
int useage(int num){
    int ans=0;
    while(num){
        ans+=use[num%10];
        num/=10;
    }
    return ans;
}
void loop(){
    scanf("%d",&n);
    int maxx=pow(10,n/7+1);
    for(int x=1;x<maxx;x++){
        if(useage(x)==n){
            printf("%d\n",x);
            return;
        }
    }
    printf("-1\n");
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int _=0;_<t;_++){
        loop();
    }
    return 0;
}