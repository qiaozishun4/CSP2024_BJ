#include<bits/stdc++.h>
using namespace std;
int ma[11]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        int flag=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=100000;i++){
            int sum=0;
            int w=i;
            while(w!=0){
                sum+=ma[w%10];
                w=w/10;
            }
            if(sum==n){
                printf("%d\n",i);
                flag=1;
                break;
            }
        }
        if(flag){
            continue;
        }
        printf("-1\n");
    }
    return 0;
}
