#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[15]={6,2,5,5,4,5,6,3,7,6};
int num[15]={-1,-1,1,7,4,2,0,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        if(n<=7&&n!=6){
            printf("%d\n",num[n]);
            continue;
        }
        if(n==6){
            printf("6\n");
            continue;
        }
        for(int i=10;;i++){
            int cnt=0;
            int ii=i;
            while(ii){
                int now=ii%10;
                ii/=10;
                cnt+=a[now];
            }
            if(cnt==n){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
